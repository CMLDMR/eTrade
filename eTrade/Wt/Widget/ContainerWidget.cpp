#include "ContainerWidget.h"

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>

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

Wt::WDialog* ContainerWidget::createDialog(const std::string &title)
{
    auto mDialog = wApp->addChild(std::make_unique<Wt::WDialog>(title));


    auto closeBtn = mDialog->footer()->addNew<Wt::WPushButton>("Kapat");

    closeBtn->clicked().connect([=](){
        wApp->removeChild(mDialog);
    });

    return mDialog;
}

void ContainerWidget::removeDialog(Wt::WDialog *mDialog)
{
    wApp->removeChild(mDialog);
}

} // namespace Widget
