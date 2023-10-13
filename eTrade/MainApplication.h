#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H


#include "Wt/WBootstrap5Theme.h"
#include <Wt/WApplication.h>
#include <Wt/WBootstrapTheme.h>

using namespace Wt;


namespace Header {
class Widget;
}


class MainApplication : public WApplication
{
public:
    MainApplication( const WEnvironment& env );

private:
    std::shared_ptr<Wt::WBootstrap5Theme> m_wtTheme;
    void init();
};

#endif // MAINAPPLICATION_H
