#ifndef BODY_SECTION_H
#define BODY_SECTION_H

#include <Wt/WContainerWidget.h>

namespace Body {

class Section : public Wt::WContainerWidget
{
public:
    Section();

private:
    void init();
};

} // namespace Body

#endif // BODY_SECTION_H
