#include "CustomerReview.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

using namespace Wt;

namespace Body {

CustomerReview::CustomerReview()
{
    setHeight(350);

    decorationStyle().setBackgroundColor(Wt::StandardColor::DarkCyan);

    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());

    layout->addStretch(1);

    auto text = layout->addWidget(std::make_unique<Wt::WText>("<h1>Customer Review</h1>"),0,Wt::AlignmentFlag::Center);

    layout->addStretch(1);
}

} // namespace Body
