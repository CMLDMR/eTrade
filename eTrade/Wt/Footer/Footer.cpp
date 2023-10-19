#include "Footer.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>


using namespace Wt;

namespace Footer {

Footer::Footer()
{
    init();
}

void Footer::init()
{
    decorationStyle().setBackgroundColor(WColor(StandardColor::DarkGray));
    setPadding(50,Side::Top|Side::Bottom);
    setContentAlignment(AlignmentFlag::Center);
    m_Content = addNew<WContainerWidget>();
    m_Content->addStyleClass(Bootstrap::Grid::row);
    m_Content->setMaximumSize(1280,WLength::Auto);

    initLogoSocial();
    initAddress();
    quickLinks();
    NewsLetter();
}

void Footer::initLogoSocial()
{
    auto container = m_Content->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::xxl(3)+
                             Bootstrap::Grid::xl(3)+
                             Bootstrap::Grid::lg(3)+
                             Bootstrap::Grid::md(3)+
                             Bootstrap::Grid::sm(6)+
                             Bootstrap::Grid::xs(6));
//    container->decorationStyle().setBackgroundColor(WColor(StandardColor::LightGray));
    container->setAttributeValue(Style::style,Style::Border::right::border("solid white 1px")+Style::Border::left::border("solid white 1px"));
//    container->setAttributeValue(Style::style,Style::Border::left::border("solid white 1px"));


    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    auto logoContainer = vLayout->addWidget(std::make_unique<WText>("<h1>Logo</h1>"));

    auto textContainer = vLayout->addWidget(std::make_unique<WText>("Diam dolor diam ipsum sit. Aliqu diam amet diam et eos. Clita erat ipsum et lorem et sit, sed stet lorem sit clita"));

    auto socialContainer = vLayout->addWidget(std::make_unique<WContainerWidget>());

    auto hLayout = socialContainer->setLayout(std::make_unique<WHBoxLayout>());

    auto Twitter = hLayout->addWidget(std::make_unique<WText>("<h1>T</h1>"));
    auto Face = hLayout->addWidget(std::make_unique<WText>("<h1>F</h1>"));
    auto Youtube = hLayout->addWidget(std::make_unique<WText>("<h1>Y</h1>"));
    auto Linkedin = hLayout->addWidget(std::make_unique<WText>("<h1>IN</h1>"));
}

void Footer::initAddress()
{
    auto container = m_Content->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::xxl(3)+
                             Bootstrap::Grid::xl(3)+
                             Bootstrap::Grid::lg(3)+
                             Bootstrap::Grid::md(3)+
                             Bootstrap::Grid::sm(6)+
                             Bootstrap::Grid::xs(6));
    container->setAttributeValue(Style::style,Style::Border::right::border("solid white 1px"));


    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    vLayout->addWidget(std::make_unique<WText>("<h2>Address</h2>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>123 Street, New York, USA</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>+012 345 67890</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>info@example.com</h5>"));

}

void Footer::quickLinks()
{
    auto container = m_Content->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::xxl(3)+
                             Bootstrap::Grid::xl(3)+
                             Bootstrap::Grid::lg(3)+
                             Bootstrap::Grid::md(3)+
                             Bootstrap::Grid::sm(6)+
                             Bootstrap::Grid::xs(6));
//    container->decorationStyle().setBackgroundColor(WColor(StandardColor::LightGray));
    container->setAttributeValue(Style::style,Style::Border::right::border("solid white 1px"));


    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    vLayout->addWidget(std::make_unique<WText>("<h2>Quick Links</h2>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>About Us</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Contact Us</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Our Services</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Terms - Condition</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Support</h5>"));
}

void Footer::NewsLetter()
{
    auto container = m_Content->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::xxl(3)+
                             Bootstrap::Grid::xl(3)+
                             Bootstrap::Grid::lg(3)+
                             Bootstrap::Grid::md(3)+
                             Bootstrap::Grid::sm(6)+
                             Bootstrap::Grid::xs(6));
    container->setAttributeValue(Style::style,Style::Border::right::border("solid white 1px"));


    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    vLayout->addWidget(std::make_unique<WText>("<h2>News Letter</h2>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Dolor amet sit justo amet elitr clita ipsum elitr est.</h5>"));
    vLayout->addWidget(std::make_unique<WText>("<h5>Sign Up</h5>"));
}

} // namespace Footer
