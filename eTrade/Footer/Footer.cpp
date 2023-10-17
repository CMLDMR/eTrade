#include "Footer.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>


using namespace Wt;

namespace Footer {

Footer::Footer()
{

    setHeight(450);

    decorationStyle().setBackgroundColor(WColor(StandardColor::DarkMagenta));

    auto layout = setLayout(std::make_unique<WVBoxLayout>());

    layout->addStretch(1);

    layout->addWidget(std::make_unique<WText>("<h1>Footer</h1>"),0,AlignmentFlag::Center);

    layout->addStretch(1);

}

} // namespace Footer
