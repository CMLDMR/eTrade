#ifndef FOOTER_FOOTER_H
#define FOOTER_FOOTER_H

#include <Wt/WContainerWidget.h>


namespace Footer {

class Footer : public Wt::WContainerWidget
{
public:
    Footer();

private:
    void init();

    void initLogoSocial();
    void initAddress();
    void quickLinks();
    void NewsLetter();

    Wt::WContainerWidget* m_Content{nullptr};
};

} // namespace Footer

#endif // FOOTER_FOOTER_H
