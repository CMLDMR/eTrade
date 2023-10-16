#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WPushButton.h>

#include "Body/Feature.h"
#include "Bootstrap5ThemaKeys.h"
#include "Header/Widget.h"

#include <Body/Slider.h>
#include <Body/Section.h>

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

    root()->addNew<Header::Widget>();

    auto slider = root()->addNew<Body::Slider>();
    slider->addSlide("Natural Food Is Always Healthy","img/carousel-1.jpg");
    slider->addSlide("Natural Food Is Always Healthy","img/carousel-2.jpg");


    auto section = root()->addNew<Body::Section>();
    auto feature = root()->addNew<Body::Feature>();

}
