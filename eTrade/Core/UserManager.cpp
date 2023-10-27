#include "UserManager.h"

namespace eCore {
namespace User {

Manager::Manager(MongoCore::DB* _mDB)
    :MongoCore::ListItem<UserItem>(_mDB)
{

}

void Manager::onList(const std::vector<UserItem> &mList)
{



}

} // namespace User
} // namespace eCore
