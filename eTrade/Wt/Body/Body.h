#ifndef BODY_H
#define BODY_H

#include <Wt/WContainerWidget.h>

#include "MongoCore/db.h"



namespace Body {

class Body : public Wt::WContainerWidget
{
public:
    Body(MongoCore::DB *_db);
};


}

#endif // BODY_H
