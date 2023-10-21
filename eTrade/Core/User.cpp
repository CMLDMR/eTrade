#include "User.h"

namespace eCore {

namespace User {

UserItem::UserItem(MongoCore::DB *mdb)
    :m_db(mdb),
    MongoCore::Item(Key::Collection)
{

}

UserItem::UserItem(UserItem *mUser)
    :m_db(mUser->db()),
    MongoCore::Item(Key::Collection)
{
    this->setDocumentView(mUser->view());
}

UserItem::UserType UserItem::getType() const
{
    auto val = element(Key::type);
    if( val ) {
        auto type = static_cast<UserType>(val.value().view().get_int32().value);
        return type;
    }

    return UserType::Unknown;
}

MongoCore::DB *UserItem::db() const
{
    return m_db;
}

} // namespace User
} // namespace eCore
