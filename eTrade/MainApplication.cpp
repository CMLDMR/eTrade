#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WPushButton.h>

#include "Bootstrap5ThemaKeys.h"

MainApplication::MainApplication(const WEnvironment &env)
    :WApplication(env)
{
    init();

//    {
//        auto text = root()->addNew<WPushButton>("Text");
//        text->addStyleClass("btn btn-warning");
//    }

    {
        auto container = root()->addNew<WContainerWidget>();
        container->addNew<WText>("sfdgsdfg");
        container->setContentAlignment(AlignmentFlag::Center);
        container->decorationStyle().setBackgroundColor(WColor(StandardColor::Cyan));

        container->addStyleClass(Bootstrap::Grid::lg(6)+Bootstrap::Grid::md(12)+"col-sm-12");
    }

    {
        auto container = root()->addNew<WContainerWidget>();
        container->addNew<WText>("sfdgsdfg");
        container->setContentAlignment(AlignmentFlag::Center);
        container->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkGreen));
        container->addStyleClass(Bootstrap::Grid::lg(6)+Bootstrap::Grid::md(12)+"col-sm-8");
    }

}

void MainApplication::init()
{
    m_wtTheme = std::make_shared<Wt::WBootstrap5Theme>();

    Wt::WApplication::instance()->setTheme(m_wtTheme);

    root()->addStyleClass("row");

}
