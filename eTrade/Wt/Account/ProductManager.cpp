#include "ProductManager.h"
#include "Wt/Account/CategoryManager.h"

#include <Wt/WApplication.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WDoubleSpinBox.h>

#include <Bootstrap/Bootstrap5ThemaKeys.h>
#include <Bootstrap/inlinestyle.h>

#include <Core/Text.h>

#include <Wt/Widget/FileUploaderWidget.h>

#include <bsoncxx/oid.hpp>
#include <any>


using namespace Wt;

namespace Account {

ProductManager::ProductManager(eCore::User::UserItem *mUser)
    :eCore::ProductManager(mUser)
{
    m_categoryManager = new eCore::CategoryManager(mUser);
    init();
}

std::shared_ptr<CategoryModel> ProductManager::createCategoryModel()
{
    m_categoryManager->UpdateList();
    auto list = m_categoryManager->List();
    auto model = std::make_shared<CategoryModel>(list);
    return model;
}


} // namespace Account


void Account::ProductManager::errorOccured(const std::string &errorText)
{
}

void Account::ProductManager::onList(const std::vector<eCore::Product> &mlist)
{
}

void Account::ProductManager::init()
{
    initHeader();
}

void Account::ProductManager::initHeader()
{
    auto container = header()->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    auto m_hLayout = container->setLayout(std::make_unique<WHBoxLayout>());

    m_hLayout->addStretch(1);

    auto m_addNewProduct = m_hLayout->addWidget(std::make_unique<WPushButton>(eCore::tr("Yeni Ürün Ekle+")));
    m_addNewProduct->addStyleClass(Bootstrap::Components::Buttons::Outline::Primary+Bootstrap::Components::Buttons::Size::Small);
    m_addNewProduct->clicked().connect(this,&ProductManager::addNewProduct);
}

void Account::ProductManager::addNewProduct()
{

    auto [ mDialog , acceptBtn ] = createDialog(eCore::tr("Yeni Ürün Ekle"));

    mDialog->setWidth(480);

    m_categoryManager->UpdateList();
    mDialog->contents()->addNew<WText>(eCore::tr("Kategori Seçiniz"))->setMargin(5,Side::Bottom);
    auto m_categoryComboBox = mDialog->contents()->addNew<WComboBox>();
    m_categoryComboBox->addStyleClass(Bootstrap::Grid::container_fluid);
    m_categoryComboBox->setMargin(10,Side::Bottom);

    auto m_categoryListModel = createCategoryModel();
    m_categoryComboBox->setModel(m_categoryListModel);



    auto m_productNameLineEdit = mDialog->contents()->addNew<WLineEdit>();
    m_productNameLineEdit->setPlaceholderText(eCore::tr("Ürün Adını Giriniz"));

    auto m_imgContainer = mDialog->contents()->addNew<WContainerWidget>();
    m_imgContainer->addStyleClass(Bootstrap::Utilities::Shadow::shadow_sm+Bootstrap::Utilities::Background::bg_light);
    m_imgContainer->setMargin(15,Side::Top|Side::Bottom);

    m_imgContainer->addNew<WText>(eCore::tr("Resim Ekle"));
    auto m_img = m_imgContainer->addNew<WImage>(WLink());
    m_img->setHeight(150);
    m_img->addStyleClass(Bootstrap::Grid::container_fluid);

    auto m_imgFileUploader = m_imgContainer->addNew<Widget::FileUploaderWidget>();
    m_img->addStyleClass(Bootstrap::Grid::container_fluid);

    mDialog->contents()->addNew<WText>(eCore::tr("Ürün Fiyatı"));
    auto m_priceDoubleSpinBox = mDialog->contents()->addNew<WDoubleSpinBox>();
    m_priceDoubleSpinBox->setMaximum(99999);
    m_priceDoubleSpinBox->setMinimum(0);

    //TODO: önceden varlığı kontrol edilecek

    //TODO: güncelleme tarihi eklenecek

    acceptBtn->clicked().connect([=, this](){

        if( ! m_imgFileUploader->isUploaded() ) {
            showInfo(eCore::tr("Resim Yüklemediniz"),Widget::ContainerWidget::InfoType::error);
                return;
        }

        if( m_productNameLineEdit->text().toUTF8().size() < 3 ) {
            showInfo(eCore::tr("Ürün Adını Eksik Girdiniz"),Widget::ContainerWidget::InfoType::error);
                return;
        }

        if( m_priceDoubleSpinBox->value() < 1 ) {
            showInfo(eCore::tr("Ürün Fiyatını Girmediniz"),Widget::ContainerWidget::InfoType::error);
                return;
        }

        auto imgOid = this->uploadfile(m_imgFileUploader->fileAbsoluteLocation());

        using eCore::Product;

        eCore::Product item;

        auto m_kategoriOid_val = m_categoryListModel->at(m_categoryComboBox->currentIndex()).oid();

        if( ! m_kategoriOid_val ) {
            showInfo(eCore::tr("Kategori Oid Hatalı"),Widget::ContainerWidget::InfoType::error);
                return;
        }
        std::string m_kategoriOid = m_kategoriOid_val.value().to_string();

        auto m_kategoriText_val = m_categoryListModel->at(m_categoryComboBox->currentIndex()).value(eCore::Category::Key::text);

        if( ! m_kategoriText_val ) {
            showInfo(eCore::tr("Kategori Adı Hatalı"),Widget::ContainerWidget::InfoType::error);
                return;
        }
        std::string m_kategoriText = m_kategoriText_val.value().view().get_string().value.data();


        item.setValue(Product::Key::categoryOid,bsoncxx::oid{m_kategoriOid});
        item.setValue(Product::Key::category,m_kategoriText);
        item.setValue(Product::Key::urunAdi,m_productNameLineEdit->text().toUTF8());
        item.setValue(Product::Key::imgOid,imgOid);
        item.setValue(Product::Key::price,m_priceDoubleSpinBox->value());
        item.setValue(Product::Key::lastUpdateTime,this->secondsSinceEpoch());

        auto ins = InsertItem(item);
        if( ins.size() ) {
            showInfo(eCore::tr("Ürün Eklendi."),Widget::ContainerWidget::InfoType::info);
            wApp->removeChild(mDialog);
            UpdateList();
        }else{
            showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
        }

    });


    mDialog->show();

}
