#ifndef BODY_H
#define BODY_H

#include <Wt/WContainerWidget.h>

#include <Core/User.h>



namespace Body {

class Body : public Wt::WContainerWidget
{
public:
    Body(eCore::User::UserItem *mUser );
};


}

#endif // BODY_H
