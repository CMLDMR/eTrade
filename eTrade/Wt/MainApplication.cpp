#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WPushButton.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Header/Widget.h"

#include "Body/Body.h"
#include "Footer/Footer.h"
#include "Account/Login.h"


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
        body->addNew<Account::Login>();
    });


//    auto slider = root()->addNew<Body::Slider>();


//    auto section = root()->addNew<Body::Section>();
//    auto feature = root()->addNew<Body::Feature>();
//    auto product = root()->addNew<Body::Product>();
//    //TODO: Daha sonra bakilacak
////    auto visitor = root()->addNew<Body::Visitor>();
////    auto customer = root()->addNew<Body::CustomerReview>();
////    root()->addNew<Body::LatestBlog>();
    root()->addNew<Footer::Footer>();

}
