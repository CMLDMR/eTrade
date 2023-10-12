#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>

#include <Wt/WPushButton.h>

#include "Bootstrap5ThemaKeys.h"
#include "Wt/WBootstrap5Theme.h"

MainApplication::MainApplication(const WEnvironment &env)
    :WApplication(env)
{

    init();

    auto row = root()->addNew<WContainerWidget>();
    row->addStyleClass(Bootstrap::Grid::row);
    for( int i = 0 ; i < 12 ; i++ ){
        auto container = row->addNew<WContainerWidget>();
        container->addNew<WText>("DarkMagenta");
        container->setContentAlignment(AlignmentFlag::Center);
        container->decorationStyle().setBackgroundColor(WColor(StandardColor::Cyan));
        container->addStyleClass(Bootstrap::Grid::xs(12)+
                                 Bootstrap::Grid::sm(6)+
                                 Bootstrap::Grid::md(4)+
                                 Bootstrap::Grid::lg(3)+
                                 Bootstrap::Grid::xl(2)+
                                 Bootstrap::Grid::xxl(1));

        std::cout << Bootstrap::Grid::lg(5) << "\n";

    }

}

void MainApplication::init()
{
    m_wtTheme = std::make_shared<Wt::WBootstrap5Theme>();
//    m_wtTheme.get()->setVersion(BootstrapVersion::v5);
//    m_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(m_wtTheme);

//    Wt::WApplication::instance()->useStyleSheet("https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css");
//    Wt::WApplication::require("https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js");


    root()->addStyleClass(Bootstrap::Grid::container_fluid);

}
