#ifndef HEADER_WIDGET_H
#define HEADER_WIDGET_H

#include <Wt/WAnchor.h>
#include <Wt/WContainerWidget.h>
#include "Core/MainHeaderInfo.h"


namespace Wt {
class WHBoxLayout;
class WText;
}

namespace Header {


class AddressContainer;
class MenuBar;

class Widget : public Wt::WContainerWidget, public eCore::HeaderInfo::MainHeaderInfoManager
{
public:
    Widget(MongoCore::DB* _mDB);


    Wt::Signal<Wt::NoClass> &clickAccount();

private:
    void init();

    AddressContainer* m_AddressContainer{nullptr};
    MenuBar* m_MenuBar{nullptr};


    Wt::Signal<Wt::NoClass> m_clickAccount;

    std::vector<eCore::HeaderInfo::MainHeaderInfo> m_HeaderList;

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // MainHeaderInfoManager interface
public:
    virtual void onList(const std::vector<eCore::HeaderInfo::MainHeaderInfo> &mlist) override;
};


class AddressContainer : public Wt::WContainerWidget
{
public:
    AddressContainer();

    void setAdress( const std::string &addressText , const bool visible = true );
    void setMailAddress( const std::string &mailAddressText , const std::string &clickUrl );
    void setFaceBookAddress( const std::string &clickUrl );
    void setTwitterAddress( const std::string &clickUrl );
    void setLinkedinAddress( const std::string &clickUrl );
    void setInstagramAddress( const std::string &clickUrl );

private:
    void init();
    Wt::WHBoxLayout* m_AddressLayout{nullptr};

    Wt::WText* m_addressText{nullptr};
    Wt::WContainerWidget* m_addressTextContainer{nullptr};

    Wt::WText* m_mailAddressText{nullptr};
    Wt::WAnchor* m_mailAnchor{nullptr};
    Wt::WAnchor* m_facebookAnchor{nullptr};
    Wt::WAnchor* m_twitterAnchor{nullptr};
    Wt::WAnchor* m_linkedinAnchor{nullptr};
    Wt::WAnchor* m_instagramAnchor{nullptr};

};

} // namespace Header

#endif // HEADER_WIDGET_H
