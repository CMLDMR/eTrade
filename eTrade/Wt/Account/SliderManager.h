#ifndef ACCOUNT_SLIDERMANAGER_H
#define ACCOUNT_SLIDERMANAGER_H

#include <Core/Slider.h>
#include <Wt/Widget/ContainerWidget.h>

namespace Account {


class SliderThumbs : public Widget::ContainerWidget, public eCore::Slider
{
public:
    SliderThumbs( const eCore::Slider &slider );
};



class SliderManager : public Widget::ContainerWidget, public eCore::SliderManager
{
public:
    SliderManager( eCore::User::UserItem* _mUserItem );

private:
    void addSlider( const std::string &path ,
                   const std::string &title,
                   const std::string &altText);

    void init();
    void initControlPanel();

    void uploadSlider();

};

} // namespace Account

#endif // ACCOUNT_SLIDERMANAGER_H
