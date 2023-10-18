#include "MainApplication.h"



int main(int argc, char *argv[])
{
    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return std::make_unique<MainApplication>(env);
    });
}
