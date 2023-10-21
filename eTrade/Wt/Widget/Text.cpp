#include "Text.h"

namespace Widget {



Text::Text(const eCore::Text &text)
    :Wt::WText(text.text())
{

}

} // namespace Widget
