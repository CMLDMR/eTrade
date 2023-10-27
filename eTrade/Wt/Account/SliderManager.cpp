#include "SliderManager.h"
#include "Bootstrap/inlinestyle.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"

#include "Wt/Widget/FileUploaderWidget.h"

#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WImage.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>
#include <Wt/WApplication.h>

using namespace Wt;

using eCore::Slider;


namespace Account {

SliderThumbs::SliderThumbs(const Slider &slider)
{

    setDocumentView(slider.view());
    content()->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
    content()->addStyleClass(Bootstrap::Utilities::Border::Size::rounded_1);
//    setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));



    auto m_Layout = content()->setLayout(std::make_unique<WVBoxLayout>());

//    auto m_imgContainer = m_Layout->addWidget(std::make_unique<WContainerWidget>());

    m_Layout->addStretch(1);

    auto m_img = m_Layout->addWidget(std::make_unique<WImage>(WLink(value(Slider::Key::imgUrl).value().view().get_string().value.data())));
    m_img->setHeight(120);

    m_Layout->addStretch(1);

    auto m_text = m_Layout->addWidget(std::make_unique<WText>(eCore::tr(this->value(Slider::Key::text).value().view().get_string().value.data())));

//    auto m_btnChange = m_Layout->addWidget(std::make_unique<WPushButton>("Değiştir"));
//    auto m_btnDel = m_Layout->addWidget(std::make_unique<WPushButton>("Sil"));

    m_Layout->addStretch(1);

}


SliderManager::SliderManager(eCore::User::UserItem *_mUserItem)
    :eCore::SliderManager(_mUserItem)
{
    init();
}

void SliderManager::addSlider(const std::string &path, const std::string &title, const std::string &altText)
{
    using eCore::Slider;

    Slider slider;
    slider.setValue(Slider::Key::text,title);
    slider.setValue(Slider::Key::imgUrl,path);
//    slider.setValue(Slider::Key::,"img/carousel-1.jpg");



    auto container = content()->addNew<SliderThumbs>(slider);
    container->addStyleClass(Bootstrap::Grid::full(3));
    container->setMargin(3,Side::Top);

    auto changeBtn = container->addNew<WPushButton>("Değiştir");
    changeBtn->addStyleClass(Bootstrap::Components::Buttons::Size::Small+Bootstrap::Components::Buttons::Normal::Secondary);

    auto delBtn = container->addNew<WPushButton>("Sil");
    delBtn->addStyleClass(Bootstrap::Components::Buttons::Size::Small+Bootstrap::Components::Buttons::Normal::Danger);

}

void SliderManager::init()
{
    setLimit(8);
    initControlPanel();
//    addSlider("img/carousel-1.jpg","sd","55");
//    addSlider("img/carousel-1.jpg","sdf","df");
//    addSlider("img/carousel-1.jpg","dsfg","sdf");
//    addSlider("img/carousel-1.jpg","dfgdzxf","sdf");

    UpdateList();
}

void SliderManager::initControlPanel()
{
    auto m_layout = header()->setLayout(std::make_unique<WHBoxLayout>());
    m_layout->addStretch(1);

    auto m_addBtn = m_layout->addWidget(std::make_unique<WPushButton>(eCore::tr("Yeni Ekle+")));
    m_addBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Primary);
    m_addBtn->clicked().connect(this,&SliderManager::uploadSlider);
}

void SliderManager::uploadSlider()
{
    auto [mDialog,acceptbtn] = createDialog("Yeni Slide Ekle","Kaydet");

    mDialog->setWidth(720);

    auto m_img = mDialog->contents()->addNew<WImage>(WLink("img/carousel-1.jpg"));
    m_img->addStyleClass(Bootstrap::Grid::container_fluid);
    m_img->setHeight(320);
    m_img->setMargin(10,Side::Bottom);

    auto m_titleLineEdit = mDialog->contents()->addNew<WLineEdit>();
    m_titleLineEdit->setPlaceholderText("Slide Başlığını Giriniz");
    m_titleLineEdit->addStyleClass(Bootstrap::Grid::container_fluid);
    m_titleLineEdit->setMargin(5,AllSides);


    auto m_altTextLineEdit = mDialog->contents()->addNew<WLineEdit>();
    m_altTextLineEdit->setPlaceholderText("Slide Açıklamasını Giriniz");
    m_altTextLineEdit->addStyleClass(Bootstrap::Grid::container_fluid);
    m_altTextLineEdit->setMargin(5,AllSides);


    auto m_fileUploader = mDialog->contents()->addNew<Widget::FileUploaderWidget>();
    m_fileUploader->addStyleClass(Bootstrap::Grid::container_fluid);
    m_fileUploader->setMargin(5,AllSides);

    m_fileUploader->Uploaded().connect([=](){
        m_img->setImageLink(WLink(m_fileUploader->fileLocation()));
    });

    acceptbtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Primary);
    acceptbtn->clicked().connect([=](){

        if( m_fileUploader->isUploaded() ) {

            eCore::Slider item;
            item.setValue(Slider::Key::altText,m_altTextLineEdit->text().toUTF8());
            item.setValue(Slider::Key::text,m_altTextLineEdit->text().toUTF8());

            auto imgOid = this->uploadfile(m_fileUploader->fileAbsoluteLocation());
            item.setValue(Slider::Key::imgOid,imgOid);

            auto ins = InsertItem(item);

            if( ins.size() ) {
                UpdateList();
            }else{
                showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
            }
            UpdateList();
            wApp->removeChild(mDialog);
        }else{
            showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
        }
    });

    mDialog->show();

}



} // namespace Account


void Account::SliderManager::errorOccured(const std::string &errorText)
{
}

void Account::SliderManager::onList(const std::vector<eCore::Slider> &mlist)
{

    content()->clear();

    for( const auto &item : mlist ) {
        auto imgUrl = downloadFileWeb(item.value(Slider::Key::imgOid).value().view().get_oid().value.to_string(),wApp->docRoot());
        addSlider(imgUrl,item.value(Slider::Key::text).value().view().get_string().value.data(),
                  item.value(Slider::Key::altText).value().view().get_string().value.data());
    }
}
