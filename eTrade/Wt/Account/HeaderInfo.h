#ifndef ACCOUNT_HEADERINFO_H
#define ACCOUNT_HEADERINFO_H

#include "Wt/Widget/ContainerWidget.h"
#include "Core/MainHeaderInfo.h"
#include "Core/User.h"

namespace Account {

class HeaderInfo : public Widget::ContainerWidget, public eCore::HeaderInfo::MainHeaderInfoManager
{
public:
    HeaderInfo(eCore::User::UserItem* mUser);



    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<eCore::HeaderInfo::MainHeaderInfo> &mlist) override;


private:
    void init();

    Wt::WLineEdit* m_adresLineEdit{nullptr};



};

} // namespace Account

#endif // ACCOUNT_HEADERINFO_H
