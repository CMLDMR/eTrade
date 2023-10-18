#include "Visitor.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

namespace Body {

Visitor::Visitor()
{
    setHeight(350);

    decorationStyle().setBackgroundColor(Wt::StandardColor::DarkGreen);

    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());

    layout->addStretch(1);

    auto text = layout->addWidget(std::make_unique<Wt::WText>("<h1>Visit US</h1>"),0,Wt::AlignmentFlag::Center);

    layout->addStretch(1);
}

} // namespace Body
