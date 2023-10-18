#include "Section.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

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

//    decorationStyle().setBackgroundColor(WColor(Wt::StandardColor::LightGray));

    setPadding(50,Side::Top|Side::Bottom);
    setContentAlignment(AlignmentFlag::Center);


    auto rContainer = addNew<WContainerWidget>();
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setMaximumSize(1280,WLength::Auto);

    auto imgContainer = rContainer->addNew<WContainerWidget>();
    imgContainer->addStyleClass(Bootstrap::Grid::xs(12)+
                                Bootstrap::Grid::sm(12)+
                                Bootstrap::Grid::md(5)+
                                Bootstrap::Grid::lg(5)+
                                Bootstrap::Grid::xl(5)+
                                Bootstrap::Grid::xxl(5));
    imgContainer->setOverflow(Overflow::Hidden);


    auto img = imgContainer->addWidget(std::make_unique<WImage>("img/about.jpg"));
//    img->setWidth(450);
    img->setHeight(450);



    auto textContainer = rContainer->addNew<WContainerWidget>();
    textContainer->addStyleClass(Bootstrap::Grid::xs(12)+
                                Bootstrap::Grid::sm(12)+
                                Bootstrap::Grid::md(7)+
                                Bootstrap::Grid::lg(7)+
                                Bootstrap::Grid::xl(7)+
                                Bootstrap::Grid::xxl(7));


    auto vLayout = textContainer->setLayout(std::make_unique<WVBoxLayout>());

    vLayout->addStretch(1);

    vLayout->addWidget(std::make_unique<WText>("<h1>Best Organic Fruits And Vegetables</h1>"),0,AlignmentFlag::Left);


    auto text = vLayout->addWidget(std::make_unique<WText>("Tempor erat elitr rebum at clita. "
                                                                "Diam dolor diam ipsum sit. "
                                                                "Aliqu diam amet diam et eos. "
                                                                "Clita erat ipsum et lorem et sit, "
                                                                "sed stet lorem sit clita duo justo magna dolore erat amet"),0,AlignmentFlag::Left);
    text->setTextAlignment(AlignmentFlag::Left);

    vLayout->addWidget(std::make_unique<WText>(" - Tempor erat elitr rebum at clita"),0,AlignmentFlag::Left);
    vLayout->addWidget(std::make_unique<WText>(" - Aliqu diam amet diam et eos"),0,AlignmentFlag::Left);
    vLayout->addWidget(std::make_unique<WText>(" - Clita duo justo magna dolore erat amet"),0,AlignmentFlag::Left);

    vLayout->addWidget(std::make_unique<WPushButton>("Read More"),0,AlignmentFlag::Left);

    vLayout->addStretch(1);


}

} // namespace Body
