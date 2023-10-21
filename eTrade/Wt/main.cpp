#include "MainApplication.h"

#include "mongocxx/instance.hpp"


int main(int argc, char *argv[])
{
    mongocxx::instance instance{};

    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return std::make_unique<MainApplication>(env);
    });
}
