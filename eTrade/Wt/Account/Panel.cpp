#include "Panel.h"

#include <Wt/WText.h>

using namespace Wt;

namespace Account {

Panel::Panel()
{
    init();
}

void Panel::init()
{

    auto loginWidget = addNew<Account::Login>();

    loginWidget->successLogin().connect([=](){

        this->clear();
        this->addNew<WText>("User Panel");
    });

}

} // namespace Account
