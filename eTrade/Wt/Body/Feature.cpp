#include "Feature.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"

using namespace Wt;

namespace Body {

Feature::Feature()
{
    init();
}

void Feature::init()
{
    setAttributeValue(Style::style,Style::background::url("img/bg-icon.png")+Style::background::repeat::norepeat+Style::background::size::cover);

    setContentAlignment(AlignmentFlag::Center);
    setPadding(50,Side::Top|Side::Bottom);

    {
        auto titleContainer = addWidget(std::make_unique<WContainerWidget>());
        titleContainer->addStyleClass(Bootstrap::Grid::container_fluid);
        titleContainer->setContentAlignment(AlignmentFlag::Center);
        titleContainer->addNew<WText>("<h1>Our Features</h1>");
    }


    {
        auto titleContainer = addWidget(std::make_unique<WContainerWidget>());
        titleContainer->addStyleClass(Bootstrap::Grid::container_fluid);
        titleContainer->setContentAlignment(AlignmentFlag::Center);
        titleContainer->addNew<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit. Ipsum diam justo sed rebum vero dolor duo.");
    }


    auto row = addNew<WContainerWidget>();
    row->addStyleClass(Bootstrap::Grid::row);
    row->setMaximumSize(1280,WLength::Auto);
    row->setMargin(15,Side::Top);


    {
        auto r1 = row->addNew<WContainerWidget>();
        r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                          Bootstrap::Grid::lg(4));
        auto layoutContainer = r1->addNew<WContainerWidget>();
        layoutContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));

        auto vLayout = layoutContainer->setLayout(std::make_unique<WVBoxLayout>());
        vLayout->setContentsMargins(2,0,2,0);
        auto imgContainer = vLayout->addWidget(std::make_unique<WContainerWidget>());
        imgContainer->addWidget(std::make_unique<WImage>(WLink("img/icon-1.png")));
        vLayout->addWidget(std::make_unique<WText>("<h2>Natural Process</h2>"));
        vLayout->addWidget(std::make_unique<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit. Ipsum diam justo sed vero dolor duo."));
        vLayout->addWidget(std::make_unique<WPushButton>("Read More"));
    }

    {
        auto r1 = row->addNew<WContainerWidget>();
        r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                          Bootstrap::Grid::lg(4));
        auto layoutContainer = r1->addNew<WContainerWidget>();
        layoutContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));

        auto vLayout = layoutContainer->setLayout(std::make_unique<WVBoxLayout>());
        vLayout->setContentsMargins(2,0,2,0);
        auto imgContainer = vLayout->addWidget(std::make_unique<WContainerWidget>());
        imgContainer->addWidget(std::make_unique<WImage>(WLink("img/icon-2.png")));
        vLayout->addWidget(std::make_unique<WText>("<h2>Organic Products</h2>"));
        vLayout->addWidget(std::make_unique<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit. Ipsum diam justo sed vero dolor duo."));
        vLayout->addWidget(std::make_unique<WPushButton>("Read More"));
    }

    {
        auto r1 = row->addNew<WContainerWidget>();
        r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                          Bootstrap::Grid::lg(4));
        auto layoutContainer = r1->addNew<WContainerWidget>();
        layoutContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));
        auto vLayout = layoutContainer->setLayout(std::make_unique<WVBoxLayout>());
        vLayout->setContentsMargins(2,0,2,0);
        auto imgContainer = vLayout->addWidget(std::make_unique<WContainerWidget>());
        imgContainer->addWidget(std::make_unique<WImage>(WLink("img/icon-3.png")));
        vLayout->addWidget(std::make_unique<WText>("<h2>Biologically Safe</h2>"));
        vLayout->addWidget(std::make_unique<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit. Ipsum diam justo sed vero dolor duo."));
        vLayout->addWidget(std::make_unique<WPushButton>("Read More"));
    }
}


} // namespace Body
