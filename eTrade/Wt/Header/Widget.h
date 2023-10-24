#ifndef HEADER_WIDGET_H
#define HEADER_WIDGET_H

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

    void setAdress( const std::string &addressText );

private:
    void init();
    Wt::WHBoxLayout* m_AddressLayout{nullptr};

    Wt::WText* m_addressText;

};

} // namespace Header

#endif // HEADER_WIDGET_H
