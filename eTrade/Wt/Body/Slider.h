#ifndef BODY_SLIDER_H
#define BODY_SLIDER_H

#include <Wt/WStackedWidget.h>
#include <Wt/Widget/ContainerWidget.h>
#include <Core/Slider.h>
#include <Core/User.h>


namespace Body {

class Slider : public Wt::WStackedWidget, public eCore::SliderManager
{
public:
    Slider( eCore::User::UserItem *mUser );

    void addSlide(const std::string &title , const std::string &backgroundImg );

private:
    void init();

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // SliderManager interface
public:
    virtual void onList(const std::vector<eCore::Slider> &mlist) override;
};

} // namespace Body

#endif // BODY_SLIDER_H
