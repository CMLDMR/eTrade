#include "ContainerWidget.h"

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WTimer.h>

using namespace Wt;

namespace Widget {

ContainerWidget::ContainerWidget()
{
    setContentAlignment(Wt::AlignmentFlag::Center);

    m_headerWidget = addNew<Wt::WContainerWidget>();
    m_headerWidget->setContentAlignment(Wt::AlignmentFlag::Center);
    m_headerWidget->setMaximumSize(1280,Wt::WLength::Auto);
    m_headerWidget->addStyleClass(Bootstrap::Grid::container_fluid);


    m_contentWidget = addNew<Wt::WContainerWidget>();
    m_contentWidget->setContentAlignment(Wt::AlignmentFlag::Center);
    m_contentWidget->setMaximumSize(1280,Wt::WLength::Auto);
    m_contentWidget->addStyleClass(Bootstrap::Grid::row);
}

Wt::WContainerWidget *ContainerWidget::header() const
{
    return m_headerWidget;
}

Wt::WContainerWidget *ContainerWidget::content() const
{
    return m_contentWidget;
}

Wt::WContainerWidget *ContainerWidget::footer()
{
    m_footerWidget = addNew<Wt::WContainerWidget>();
    m_footerWidget->setContentAlignment(Wt::AlignmentFlag::Center);
    m_footerWidget->setMaximumSize(1280,Wt::WLength::Auto);
    m_footerWidget->addStyleClass(Bootstrap::Grid::container_fluid);
    return m_footerWidget;
}

std::pair<Wt::WDialog*,Wt::WPushButton*> ContainerWidget::createDialog(const std::string &title, const std::string &acceptBtnName )
{
    auto mDialog = wApp->addChild(std::make_unique<Wt::WDialog>(title));
    auto acceptBtn = mDialog->footer()->addNew<Wt::WPushButton>("Kaydet");


    auto closeBtn = mDialog->footer()->addNew<Wt::WPushButton>("Kapat");

    closeBtn->clicked().connect([=](){
        wApp->removeChild(mDialog);
    });

    return std::make_pair(mDialog,acceptBtn);
}

void ContainerWidget::removeDialog(Wt::WDialog *mDialog)
{
    wApp->removeChild(mDialog);
}

void ContainerWidget::showInfo(const std::string &message, const InfoType type)
{
    //TODO: remove if time finished

    auto m_infoWidget = wApp->instance()->root()->addWidget(std::make_unique<Wt::WContainerWidget>());

    m_infoWidget->addStyleClass("informer");
    m_infoWidget->setPadding(15,AllSides);
    m_infoWidget->setContentAlignment(AlignmentFlag::Center);
    m_infoWidget->setMinimumSize(350,WLength::Auto);
    m_infoWidget->setZIndex(1101);

    m_infoWidget->setPositionScheme(Wt::PositionScheme::Fixed);

    m_infoWidget->setOffsets(-30,Wt::Side::Bottom);
    m_infoWidget->setOffsets(WLength("40%"),Wt::Side::Left);

    m_infoWidget->addNew<Wt::WText>("<b>"+message+"</b>");
    switch ( type ) {
    case InfoType::info:
        m_infoWidget->setAttributeValue(Style::style,Style::background::color::color(Style::color::Purple::DodgerBlue)+
                                                       Style::color::color(Style::color::White::AliceBlue));
        break;
    case InfoType::error:
        m_infoWidget->setAttributeValue(Style::style,Style::background::color::color(Style::color::Red::DarkRed)+
                                                       Style::color::color(Style::color::White::AliceBlue));
        break;
    default:
        break;
    }

    Wt::WTimer::singleShot(std::chrono::seconds(5),[=](){
        wApp->instance()->root()->removeWidget(m_infoWidget);
    });

}

} // namespace Widget
