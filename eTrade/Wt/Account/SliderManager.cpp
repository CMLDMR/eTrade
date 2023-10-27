#include "SliderManager.h"
#include "Bootstrap/inlinestyle.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Wt/WVBoxLayout.h"

#include <Wt/WText.h>
#include <Wt/WImage.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>

using namespace Wt;

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

void SliderManager::addSlider()
{
    using eCore::Slider;

    Slider slider;
    slider.setValue(Slider::Key::text,"Slider Text Message");
    slider.setValue(Slider::Key::imgUrl,"img/carousel-1.jpg");



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
    addSlider();
    addSlider();
    addSlider();
    addSlider();
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
    mDialog->show();

    using eCore::Slider;

    Slider slider;
    slider.setValue(Slider::Key::text,"Slider Test Message");
    slider.setValue(Slider::Key::imgUrl,"img/carousel-1.jpg");

    mDialog->contents()->addNew<SliderThumbs>(slider);

    acceptbtn->clicked().connect([=](){
        addSlider();
    });

}



} // namespace Account
