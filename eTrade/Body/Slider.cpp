#include "Slider.h"
#include "Wt/WCssDecorationStyle.h"

#include <Wt/WText.h>

using namespace Wt;

namespace Body {

Slider::Slider()
{
    setHeight(450);
    decorationStyle().setBackgroundColor(Wt::StandardColor::DarkMagenta);
    setContentAlignment(Wt::AlignmentFlag::Center);
    addNew<WText>("<h2>Image Text Slider</h2>");
    decorationStyle().setForegroundColor(StandardColor::White);

}

} // namespace Body
