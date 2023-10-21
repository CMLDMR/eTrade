#ifndef ACCOUNT_LOGIN_H
#define ACCOUNT_LOGIN_H

#include <Wt/WContainerWidget.h>

namespace Account {

class Login : public Wt::WContainerWidget
{
public:
    Login();

private:
    void init();
};

} // namespace Account

#endif // ACCOUNT_LOGIN_H
