#include "ProductManager.h"
#include "Wt/Account/CategoryManager.h"
#include "Wt/WVBoxLayout.h"

#include <Wt/WApplication.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WDoubleSpinBox.h>
#include <Wt/WDateTime.h>
#include <Wt/WTextEdit.h>

#include <Bootstrap/Bootstrap5ThemaKeys.h>
#include <Bootstrap/inlinestyle.h>

#include <Core/Text.h>

#include <Wt/Widget/FileUploaderWidget.h>

#include <bsoncxx/oid.hpp>



using namespace Wt;

namespace Account {

ProductManager::ProductManager(eCore::User::UserItem *mUser)
    :eCore::ProductManager(mUser)
{
    m_categoryManager = new eCore::CategoryManager(mUser);
    // init();
}

std::shared_ptr<CategoryModel> ProductManager::createCategoryModel()
{
    m_categoryManager->UpdateList();
    auto list = m_categoryManager->List();
    auto model = std::make_shared<CategoryModel>(list);
    return model;
}

void ProductManager::addProduct(const eCore::Product &item)
{
    auto rcontainer = content()->addNew<WContainerWidget>();
    rcontainer->addStyleClass( Bootstrap::Grid::full( 3 ) );
    rcontainer->setMargin( 10 , Side::Bottom );

    auto container = rcontainer->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Utilities::Background::bg_primary+
                             Bootstrap::Utilities::Background::bg_light+
                             Bootstrap::Utilities::Shadow::shadow_lg);

    auto m_vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    auto m_imgOid = item.value(eCore::Product::Key::imgOid);
    if( m_imgOid ) {
        auto m_imgUrl = downloadFileWeb(m_imgOid.value().view().get_oid().value.to_string(),wApp->docRoot());
        auto m_img = m_vLayout->addWidget(std::make_unique<WImage>(WLink(m_imgUrl)));
        m_img->setHeight(250);
        m_img->setWidth(WLength::Auto);
    }
    else {
        auto m_img = m_vLayout->addWidget(std::make_unique<WImage>(WLink("img/imgerror.jpg")));
        m_img->setHeight(250);
        m_img->setWidth(WLength::Auto);
    }
    auto m_titleVal = item.value(eCore::Product::Key::urunAdi);
    if( m_titleVal ) {
        auto m_titleText = m_vLayout->addWidget(std::make_unique<WText>(m_titleVal.value().view().get_string().value.data()));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_catVal = item.value(eCore::Product::Key::category);
    if( m_catVal ) {
        auto m_catText = m_vLayout->addWidget(std::make_unique<WText>(m_catVal.value().view().get_string().value.data()));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_priceVal = item.value(eCore::Product::Key::price);
    if( m_priceVal ) {
        auto m_priceText = m_vLayout->addWidget(std::make_unique<WText>(WString("{1} TL").arg(m_priceVal.value().view().get_double().value)));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_btnController = m_vLayout->addWidget(std::make_unique<WContainerWidget>());
    m_btnController->addStyleClass(Bootstrap::Grid::row+Bootstrap::Components::Buttons::group);

    auto m_viewChangeBtn = m_btnController->addNew<WPushButton>(eCore::tr("Değiştir"));
    m_viewChangeBtn->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Components::Buttons::Normal::Primary+Bootstrap::Components::Buttons::Size::Small);
    m_viewChangeBtn->clicked().connect([=,this](){
        this->changeProduct(item);
    });

    auto m_viewDetailsBtn = m_btnController->addNew<WPushButton>(eCore::tr("Detay"));
     m_viewDetailsBtn->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Components::Buttons::Normal::Secondary+Bootstrap::Components::Buttons::Size::Small);
     m_viewDetailsBtn->clicked().connect([=,this](){
         this->changeDetails(item);
    });

    auto m_addToCartbtn = m_btnController->addNew<WPushButton>(eCore::tr("Sil"));
    m_addToCartbtn->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Components::Buttons::Normal::Warning+Bootstrap::Components::Buttons::Size::Small);
    m_addToCartbtn->clicked().connect([=,this](){
        this->deleteProduct(item.oid().value().to_string(),item.value(eCore::Product::Key::imgOid).value().view().get_oid().value.to_string());
    });
    //BUG:  Zaman dönüşümü hatalı çalışıyor
    auto epochTime = item.value(eCore::Product::Key::lastUpdateTime).value().view().get_int64().value;
    WDateTime dateTime((std::chrono::system_clock::from_time_t(epochTime)));
    m_vLayout->addWidget(std::make_unique<WText>("Son Güncelleme "+dateTime.toString("hh:mm dd/MM/yyyy")));


}


} // namespace Account


void Account::ProductManager::errorOccured(const std::string &errorText)
{
    showInfo( errorText , Widget::ContainerWidget::InfoType::error );
}

void Account::ProductManager::onList(const std::vector<eCore::Product> &mlist)
{
    content()->clear();

    for( const auto &item : mlist ) {
        addProduct(item);
    }
}

void Account::ProductManager::init()
{
    initHeader();

    UpdateList();
}

void Account::ProductManager::initHeader()
{
    header()->setMargin(25,Side::Top);
    header()->addWidget(std::make_unique<WText>("<h4>"+eCore::tr("Ürünler")+"</h4>"));


    auto container = header()->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    auto m_hLayout = container->setLayout(std::make_unique<WHBoxLayout>());

    // auto m_catControlContainer = header()->addNew<WContainerWidget>();
    // m_catControlContainer->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Components::Buttons::group);

    auto m_categoryList = createCategoryModel();
    for( int i = 0 ; i < m_categoryList->size(); i++ ) {
        auto item = m_categoryList->at(i);
        auto btnName = item.value(eCore::Category::Key::text).value().view().get_string().value.data();
        auto catBtn = m_hLayout->addWidget(std::make_unique<WPushButton>(btnName));
        catBtn->addStyleClass(Bootstrap::Components::Buttons::Size::Small + Bootstrap::Components::Buttons::Outline::Success);
        catBtn->clicked().connect([=, this](){
            eCore::Product filter;
            filter.setValue(eCore::Product::Key::categoryOid,item.oid().value());
            UpdateList(filter);
        });
    }

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
        item.setValue(Product::Key::lastUpdateTime,WDateTime::currentDateTime().toTimePoint().time_since_epoch().count());

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

void Account::ProductManager::changeProduct(const eCore::Product &product)
{

    auto [ mDialog , acceptBtn ] = createDialog(eCore::tr("Değiştir"));

    mDialog->setWidth(480);

    m_categoryManager->UpdateList();
    mDialog->contents()->addNew<WText>(eCore::tr("Kategori Seçiniz"))->setMargin(5,Side::Bottom);
    auto m_categoryComboBox = mDialog->contents()->addNew<WComboBox>();
    m_categoryComboBox->addStyleClass(Bootstrap::Grid::container_fluid);
    m_categoryComboBox->setMargin(10,Side::Bottom);

    auto m_categoryListModel = createCategoryModel();
    m_categoryComboBox->setModel(m_categoryListModel);
    for( int i = 0 ; i < m_categoryListModel->size() ; i++ ) {
        if ( m_categoryListModel->at(i).value(eCore::Category::Key::text).value().view().get_string().value ==
            product.value(eCore::Product::Key::category).value().view().get_string().value ){
            m_categoryComboBox->setCurrentIndex(i);
            break;
        }
    }



    auto m_productNameLineEdit = mDialog->contents()->addNew<WLineEdit>();
    m_productNameLineEdit->setPlaceholderText(eCore::tr("Ürün Adını Giriniz"));
    m_productNameLineEdit->setText(product.value(eCore::Product::Key::urunAdi).value().view().get_string().value.data());

    auto m_imgContainer = mDialog->contents()->addNew<WContainerWidget>();
    m_imgContainer->addStyleClass(Bootstrap::Utilities::Shadow::shadow_sm+Bootstrap::Utilities::Background::bg_light);
    m_imgContainer->setMargin(15,Side::Top|Side::Bottom);

    m_imgContainer->addNew<WText>(eCore::tr("Resim Ekle"));

    auto m_imgUrl = downloadFileWeb(product.value(eCore::Product::Key::imgOid).value().view().get_oid().value.to_string(),wApp->docRoot());
    auto m_img = m_imgContainer->addNew<WImage>(WLink(m_imgUrl));
    m_img->setHeight(150);
    m_img->addStyleClass(Bootstrap::Grid::container_fluid);

    auto m_imgFileUploader = m_imgContainer->addNew<Widget::FileUploaderWidget>();
    m_img->addStyleClass(Bootstrap::Grid::container_fluid);

    mDialog->contents()->addNew<WText>(eCore::tr("Ürün Fiyatı"));
    auto m_priceDoubleSpinBox = mDialog->contents()->addNew<WDoubleSpinBox>();
    m_priceDoubleSpinBox->setMaximum(99999);
    m_priceDoubleSpinBox->setMinimum(0);
    m_priceDoubleSpinBox->setValue(product.value(eCore::Product::Key::price).value().view().get_double().value);

    //TODO: önceden varlığı kontrol edilecek

    //TODO: güncelleme tarihi eklenecek

    acceptBtn->clicked().connect([=, this](){

        using eCore::Product;

        eCore::Product item;


        if( m_productNameLineEdit->text().toUTF8().size() < 3 ) {
            showInfo(eCore::tr("Ürün Adını Eksik Girdiniz"),Widget::ContainerWidget::InfoType::error);
                return;
        }

        //BUG: hata kontrolü yapılmadı
        if( m_productNameLineEdit->text().toUTF8() != product.value(eCore::Product::Key::urunAdi).value().view().get_string().value.data() ) {
            item.setValue(Product::Key::urunAdi,m_productNameLineEdit->text().toUTF8());
        }



        if( m_priceDoubleSpinBox->value() < 1 ) {
            showInfo(eCore::tr("Ürün Fiyatını Girmediniz"),Widget::ContainerWidget::InfoType::error);
                return;
        }

        if( m_imgFileUploader->isUploaded() ) {
            auto imgOid = this->uploadfile(m_imgFileUploader->fileAbsoluteLocation());
            item.setValue(eCore::Product::Key::imgOid,imgOid);
        }



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

        if( m_kategoriText != product.value(Product::Key::category).value().view().get_string().value.data() ) {
            item.setValue(Product::Key::categoryOid,bsoncxx::oid{m_kategoriOid});
            item.setValue(Product::Key::category,m_kategoriText);
        }


        if( m_priceDoubleSpinBox->value() != product.value(Product::Key::price).value().view().get_double().value ){
            item.setValue(Product::Key::price,m_priceDoubleSpinBox->value());
        }


        if( item.view().empty() )
            return;


        //BUG:  Zaman dönüşümü hatalı çalışıyor
        item.setValue(Product::Key::lastUpdateTime,WDateTime::currentDateTime().toTimePoint().time_since_epoch().count());
        item.setOid(product.oid().value());

        auto upt = UpdateItem(item);
        if( upt ) {
            showInfo(eCore::tr("Ürün Güncellendi."),Widget::ContainerWidget::InfoType::info);
            wApp->removeChild(mDialog);
            UpdateList();
        }else{
            showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
        }

    });


    mDialog->show();
}

void Account::ProductManager::deleteProduct( const std::string &oid, const std::string &imgOid )
{
    auto [mDialog,acceptBtn] = askDialog(eCore::tr("Silmek İstediğinize Emin misiniz?"));

    acceptBtn->clicked().connect([=, this](){
        if( deleteGridFS( imgOid ) ){
            eCore::Product filter;
            filter.setOid( oid );
            if( DeleteItem( filter ) ) {
                removeDialog(mDialog);
                showInfo("Silindi");
                UpdateList();
            }
            else{
                showInfo( "Resim Silindi Ancak Item Silinemedi" , Widget::ContainerWidget::InfoType::error );
            }
        }
        else{
            showInfo( "Resim Silinemedi" , Widget::ContainerWidget::InfoType::error );
        }
    });
}

void Account::ProductManager::changeDetails(const eCore::Product &product)
{
    auto [ mDialog , acceptBtn ] = createDialog( "Ürüne Detay Ekle" );
    mDialog->setWidth(WLength(750));


    auto m_contextText = mDialog->contents()->addNew<WTextEdit>();
    auto m_explainHtmlValue = product.value(eCore::Product::Key::explainHtml);
    if ( m_explainHtmlValue ) {
        m_contextText->setText(product.value(eCore::Product::Key::explainHtml).value().view().get_string().value.data());
    }

    acceptBtn->clicked().connect([=,this]{
        using eCore::Product;

        eCore::Product item;

        item.setValue( Product::Key::explainHtml , m_contextText->text().toUTF8() );
        item.setValue( Product::Key::lastUpdateTime , WDateTime::currentDateTime().toTimePoint().time_since_epoch().count() );
        item.setOid(product.oid().value().to_string());

        auto upt = UpdateItem(item);
        if( upt ) {
            showInfo(eCore::tr("Ürün Güncellendi."),Widget::ContainerWidget::InfoType::info);
            wApp->removeChild(mDialog);
            UpdateList();
        }else{
            showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
        }
    });
    mDialog->show();
}
