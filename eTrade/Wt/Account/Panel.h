#ifndef ACCOUNT_PANEL_H
#define ACCOUNT_PANEL_H

#include <Wt/WContainerWidget.h>

#include "Login.h"

namespace Account {

class Panel : public Wt::WContainerWidget
{
public:
    Panel();

private:
    void init();
};

} // namespace Account

#endif // ACCOUNT_PANEL_H
