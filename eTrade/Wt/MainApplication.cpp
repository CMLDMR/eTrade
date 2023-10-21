#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WPushButton.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Header/Widget.h"

#include "Body/Body.h"
#include "Footer/Footer.h"
#include "Wt/Account/Panel.h"


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

    auto m_headerContainer = root()->addNew<Header::Widget>();


    auto body = root()->addNew<Body::Body>();

    m_headerContainer->clickAccount().connect([=](){
        body->clear();
        body->addNew<Account::Panel>();
    });


    root()->addNew<Footer::Footer>();

}
