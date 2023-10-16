#include "Section.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>

#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;


using namespace Wt;

namespace Body {

Section::Section()
{


    init();
}

void Section::init()
{

    decorationStyle().setBackgroundColor(WColor(Wt::StandardColor::LightGray));


    auto layout = setLayout(std::make_unique<WHBoxLayout>());


    layout->addStretch(1);


    auto img = layout->addWidget(std::make_unique<WImage>("img/carousel-1.jpg"));


    img->setWidth(450);
    img->setHeight(450);
    img->setAttributeValue("object-fit","contain");

    auto container = layout->addWidget(std::make_unique<WContainerWidget>());

    container->setWidth(650);

    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    vLayout->addStretch(1);

    vLayout->addWidget(std::make_unique<WText>("<h1>Best Organic Fruits And Vegetables</h1>"));

    vLayout->addWidget(std::make_unique<WText>("Tempor erat elitr rebum at clita. "
                                               "Diam dolor diam ipsum sit. "
                                               "Aliqu diam amet diam et eos. "
                                               "Clita erat ipsum et lorem et sit, "
                                               "sed stet lorem sit clita duo justo magna dolore erat amet"));

    vLayout->addStretch(1);


    layout->addStretch(1);
}

} // namespace Body
