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

#include <mongocxx/exception/exception.hpp>

#include "../../../_url.h"


MainApplication::MainApplication(const WEnvironment &env)
    :WApplication(env)
{

    m_client = new mongocxx::client(mongocxx::uri(_url));

    m_dbmongocxx = m_client->database(_db);

    m_db = new MongoCore::DB(&m_dbmongocxx);

    m_user = new eCore::User::UserItem(m_db);

    init();
}

void MainApplication::init()
{
    m_wtTheme = std::make_shared<Wt::WBootstrap5Theme>();
    Wt::WApplication::instance()->setTheme(m_wtTheme);
    root()->addStyleClass(Bootstrap::Grid::container_fluid);

    WApplication::useStyleSheet(WLink("css/informer.css"));

    auto m_headerContainer = root()->addNew<Header::Widget>(m_db);


    auto body = root()->addNew<Body::Body>(m_user);

    m_headerContainer->clickAccount().connect([=, this](){
        body->clear();
        body->addNew<Account::Panel>(m_db);
    });

    m_headerContainer->MenuBarWidget()->clickHome().connect([=](){
        body->init();
    });


    root()->addNew<Footer::Footer>();

}
