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
    Wt::WCheckBox* m_adresCheckBox{nullptr};
    void updateAddress();

    Wt::WLineEdit* m_mailadresLineEdit{nullptr};
    Wt::WLineEdit* m_mainUrlAddressLine{nullptr};
    void updateMailAddress();

    Wt::WLineEdit* m_faceBookLine{nullptr};
    void updateFaceBookURL();

    Wt::WLineEdit* m_twitterLine{nullptr};
    void updateTwitterURL();

    Wt::WLineEdit* m_linkedinLine{nullptr};
    void updateLinkedinURL();

    Wt::WLineEdit* m_instagramLine{nullptr};
    void updateInstagramURL();
};

} // namespace Account

#endif // ACCOUNT_HEADERINFO_H
