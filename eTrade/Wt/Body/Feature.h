#ifndef BODY_FEATURE_H
#define BODY_FEATURE_H

#include <Wt/WContainerWidget.h>


namespace Body {

class Feature : public Wt::WContainerWidget
{
public:
    Feature();

private:
    void init();
};

} // namespace Body

#endif // BODY_FEATURE_H
