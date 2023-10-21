#ifndef WIDGET_TEXT_H
#define WIDGET_TEXT_H

#include <Wt/WText.h>
#include "Core/Text.h"


namespace Widget {

class Text : public Wt::WText
{
public:
    Text( const eCore::Text &text );

};

} // namespace Widget

#endif // WIDGET_TEXT_H
