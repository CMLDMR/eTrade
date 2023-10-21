#ifndef HEADER_WIDGET_H
#define HEADER_WIDGET_H

#include <Wt/WContainerWidget.h>


namespace Wt {
class WHBoxLayout;
}

namespace Header {


class AddressContainer;
class MenuBar;

class Widget : public Wt::WContainerWidget
{
public:
    Widget();


    Wt::Signal<Wt::NoClass> &clickAccount();

private:
    void init();

    AddressContainer* m_AddressContainer{nullptr};
    MenuBar* m_MenuBar{nullptr};


    Wt::Signal<Wt::NoClass> m_clickAccount;
};


class AddressContainer : public Wt::WContainerWidget
{
public:
    AddressContainer();

private:
    void init();
    Wt::WHBoxLayout* m_AddressLayout{nullptr};

};

} // namespace Header

#endif // HEADER_WIDGET_H
