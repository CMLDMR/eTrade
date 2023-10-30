#ifndef BODY_H
#define BODY_H

#include <Wt/WContainerWidget.h>

#include <Core/User.h>



namespace Body {

class Body : public Wt::WContainerWidget
{
public:
    Body(eCore::User::UserItem *mUser );

    void init();

private:
    eCore::User::UserItem *m_User;
};


}

#endif // BODY_H
