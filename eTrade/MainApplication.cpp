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
}

void MainApplication::init()
{
    m_wtTheme = std::make_shared<Wt::WBootstrap5Theme>();
    Wt::WApplication::instance()->setTheme(m_wtTheme);
    root()->addStyleClass(Bootstrap::Grid::container_fluid);
}
