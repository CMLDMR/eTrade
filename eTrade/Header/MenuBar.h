#ifndef HEADER_MENUBAR_H
#define HEADER_MENUBAR_H

#include <Wt/WContainerWidget.h>

namespace Wt {
class WHBoxLayout;
}

namespace Header {

class MenuBar : public Wt::WContainerWidget
{
public:
    MenuBar();


private:
    void init();
    Wt::WHBoxLayout* m_Layout;
    Wt::WContainerWidget* m_LogoContainer;
};

} // namespace Header

#endif // HEADER_MENUBAR_H
