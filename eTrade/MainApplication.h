#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>

using namespace Wt;


class MainApplication : public WApplication
{
public:
    MainApplication( const WEnvironment& env );
};

#endif // MAINAPPLICATION_H
