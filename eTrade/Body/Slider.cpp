#include "Slider.h"
#include "Wt/WCssDecorationStyle.h"
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include "inlinestyle.h"

using namespace Wt;

namespace Body {

Slider::Slider()
{
    init();
}

void Slider::addSlide(const std::string &title, const std::string &backgroundImg)
{

    auto container = std::make_unique<WContainerWidget>();

    container->setAttributeValue(Style::style,Style::background::url(backgroundImg)+
                                                   Style::background::size::cover+
                                                   Style::background::repeat::norepeat);


    auto layout = container->setLayout(std::make_unique<WVBoxLayout>());
    layout->addStretch(1);
    auto titleText = layout->addWidget(std::make_unique<WText>("<h1>"+title+"</h1>"));
    titleText->setTextAlignment(AlignmentFlag::Center);
    layout->addStretch(1);
    container->setHeight(450);

    insertWidget(0,std::move(container));

}

void Slider::init()
{
    clicked().connect([=](){
        setCurrentIndex((currentIndex()+1)%count());
    });
}

} // namespace Body
