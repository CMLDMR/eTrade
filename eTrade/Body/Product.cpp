#include "Product.h"


#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

using namespace Wt;

namespace Body {

Product::Product()
{

    setHeight(650);

    decorationStyle().setBackgroundColor(Wt::StandardColor::DarkRed);

    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());

    layout->addStretch(1);

    auto text = layout->addWidget(std::make_unique<Wt::WText>("<h1>Products</h1>"),0,Wt::AlignmentFlag::Center);

    layout->addStretch(1);
}

} // namespace Body
