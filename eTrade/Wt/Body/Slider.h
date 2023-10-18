#ifndef BODY_SLIDER_H
#define BODY_SLIDER_H

#include <Wt/WStackedWidget.h>

namespace Body {

class Slider : public Wt::WStackedWidget
{
public:
    Slider();

    void addSlide( const std::string &title , const std::string &backgroundImg );

private:
    void init();
};

} // namespace Body

#endif // BODY_SLIDER_H
