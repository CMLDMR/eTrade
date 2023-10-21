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


    Wt::WContainerWidget *accoutContainer() const;

private:
    void init();
    Wt::WHBoxLayout* m_Layout;
    Wt::WContainerWidget* m_LogoContainer;

    Wt::WContainerWidget* m_accoutContainer;
};

} // namespace Header

#endif // HEADER_MENUBAR_H
