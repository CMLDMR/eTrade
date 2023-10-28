#include "ProductManager.h"

#include <Wt/WText.h>

using namespace Wt;

namespace Account {

ProductManager::ProductManager(eCore::User::UserItem *mUser)
    :m_User(mUser)
{
    content()->addNew<WText>("sdfsdf");
}

} // namespace Account
