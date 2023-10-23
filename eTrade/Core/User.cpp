#include "User.h"

namespace eCore {

namespace User {

UserItem::UserItem()
    :MongoCore::Item(Key::Collection)
{

}

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

UserItem &UserItem::setType(const UserType type)
{
    this->append(Key::type,bsoncxx::types::b_int32{static_cast<int>(type)});
    return *this;
}

UserItem &UserItem::setUserName(const std::string &userName)
{
    this->append(Key::username,userName);
    return *this;
}

UserItem &UserItem::setUserPassword(const std::string &userPassword)
{
    this->append(Key::password,userPassword);
    return *this;
}

std::string UserItem::getUserName() const
{
    auto val = element(Key::username);
    if( val ) {
        return val.value().view().get_string().value.data();
    }
    return "";
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
