#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H


#include <Wt/WBootstrap5Theme.h>
#include <Wt/WApplication.h>
#include <Wt/WBootstrapTheme.h>

#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>


#include "MongoCore/db.h"

using namespace Wt;


namespace Header {
class Widget;
}

namespace Body {
class Slider;
}


class MainApplication : public WApplication
{
public:
    MainApplication( const WEnvironment& env );

private:
    std::shared_ptr<Wt::WBootstrap5Theme> m_wtTheme;
    void init();


    mongocxx::client* m_client;
    mongocxx::database m_dbmongocxx;

    MongoCore::DB* m_db;
};

#endif // MAINAPPLICATION_H
