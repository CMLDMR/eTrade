#ifndef ACCOUNT_LOGIN_H
#define ACCOUNT_LOGIN_H

#include <Wt/WContainerWidget.h>

namespace Account {

class Login : public Wt::WContainerWidget
{
public:
    Login();


    Wt::Signal<Wt::NoClass> &successLogin();
private:
    void init();

    Wt::Signal<Wt::NoClass> m_Success;
};

} // namespace Account

#endif // ACCOUNT_LOGIN_H
