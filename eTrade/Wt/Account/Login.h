#ifndef ACCOUNT_LOGIN_H
#define ACCOUNT_LOGIN_H

#include <Wt/WContainerWidget.h>

#include "Core/User.h"


namespace Account {

class Login : public Wt::WContainerWidget
{
public:
    Login(eCore::User::UserItem *mUser);


    Wt::Signal<Wt::NoClass> &successLogin();
private:
    void init();

    void checkUser( const std::string &username , const std::string &password );

    Wt::Signal<Wt::NoClass> m_Success;

    eCore::User::UserItem* m_User;
};

} // namespace Account

#endif // ACCOUNT_LOGIN_H
