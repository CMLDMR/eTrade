#include "MenuBar.h"
#include "Wt/WCssDecorationStyle.h"
#include "Wt/WHBoxLayout.h"

#include <Wt/WText.h>

using namespace Wt;

namespace Header {

MenuBar::MenuBar()
{

    init();

}

void MenuBar::init()
{
    setPadding(15,Side::Top);
    setPadding(5,Side::Bottom);

    m_Layout = setLayout(std::make_unique<WHBoxLayout>());
    m_Layout->setContentsMargins(0,25,0,15);

    m_LogoContainer = m_Layout->addWidget(std::make_unique<WContainerWidget>());

    m_LogoContainer->setMinimumSize(200,WLength::Auto);
    m_LogoContainer->decorationStyle().setBackgroundColor(StandardColor::DarkBlue);
    m_LogoContainer->decorationStyle().setForegroundColor(StandardColor::White);
    m_LogoContainer->addNew<WText>("LOGO");
    m_LogoContainer->setPadding(5,Side::Top|Side::Bottom);
    m_LogoContainer->setContentAlignment(AlignmentFlag::Center);

    m_Layout->addStretch(1);

    //TODO: implement regular function
    auto fMenu = [=]( const std::string &name ){
        auto container = std::make_unique<WContainerWidget>();
        container->addWidget(std::make_unique<WText>(name));
        container->decorationStyle().setBackgroundColor(StandardColor::DarkGray);
        container->decorationStyle().setForegroundColor(StandardColor::White);
        container->setPadding(5,Side::Top|Side::Bottom);
        container->setPadding(3,Side::Left|Side::Right);
        return container;
    };

    //TODO: define signal per menu
    m_Layout->addWidget(std::move(fMenu("Home")));
    m_Layout->addWidget(std::move(fMenu("About Us")));
    m_Layout->addWidget(std::move(fMenu("Products")));
    m_Layout->addWidget(std::move(fMenu("Pages")));
    m_Layout->addWidget(std::move(fMenu("Contact Us")));

    auto separator = m_Layout->addWidget(std::make_unique<WContainerWidget>());
    separator->decorationStyle().setBorder(WBorder(BorderStyle::Groove,BorderWidth::Thin,StandardColor::DarkGray),Side::Left);
    separator->setMargin(15,Side::Left|Side::Right);

    m_Layout->addWidget(std::move(fMenu("Search")));


    auto accoutContainer = fMenu("Account");
    m_accoutContainer = accoutContainer.get();
    m_Layout->addWidget(std::move(accoutContainer));


    m_Layout->addWidget(std::move(fMenu("Orders")));
}

Wt::WContainerWidget *MenuBar::accoutContainer() const
{
    return m_accoutContainer;
}

} // namespace Header
