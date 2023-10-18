#include "Feature.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WLineEdit.h>

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
        decorationStyle().setBackgroundColor(WColor(Wt::StandardColor::DarkGray));

        setContentAlignment(AlignmentFlag::Center);
        setPadding(15,Side::Bottom);

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
            row->setMaximumSize(1024,WLength::Auto);


            {
                auto r1 = row->addNew<WContainerWidget>();
                r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                                  Bootstrap::Grid::lg(4));
                auto content = r1->addNew<WContainerWidget>();
                content->setHeight(250);
                content->setAttributeValue(Style::style,Style::background::color::color("white"));

            }

            {
                auto r1 = row->addNew<WContainerWidget>();
                r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                                  Bootstrap::Grid::lg(4));
                auto content = r1->addNew<WContainerWidget>();
                content->setHeight(250);
                content->setAttributeValue(Style::style,Style::background::color::color("white"));

            }

            {
                auto r1 = row->addNew<WContainerWidget>();
                r1->addStyleClass(Bootstrap::Grid::xxl(4)+
                                  Bootstrap::Grid::lg(4));
                auto content = r1->addNew<WContainerWidget>();
                content->setHeight(250);
                content->setAttributeValue(Style::style,Style::background::color::color("white"));

            }
}


} // namespace Body
