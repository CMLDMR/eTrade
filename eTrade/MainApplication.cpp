#include "MainApplication.h"

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>

MainApplication::MainApplication(const WEnvironment &env)
    :WApplication(env)
{


    root()->addNew<WText>("Text");
}
