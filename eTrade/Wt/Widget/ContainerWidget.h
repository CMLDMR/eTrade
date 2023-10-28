#ifndef WIDGET_CONTAINERWIDGET_H
#define WIDGET_CONTAINERWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>

namespace Widget {

class ContainerWidget : public Wt::WContainerWidget
{
public:
    ContainerWidget();

    Wt::WContainerWidget *header() const;

    Wt::WContainerWidget *content() const;

    Wt::WContainerWidget *footer();

    std::pair<Wt::WDialog*,Wt::WPushButton*> createDialog( const std::string &title , const std::string &acceptBtnName = "Tamam");
    void removeDialog( Wt::WDialog* mDialog );
    std::pair<Wt::WDialog*,Wt::WPushButton*> askDialog( const std::string &message );


    enum class InfoType {
        info,
        warn,
        critical,
        error,
        unknown
    };

    void showInfo( const std::string &message , const InfoType type = InfoType::info );

private:
    Wt::WContainerWidget* m_headerWidget;
    Wt::WContainerWidget* m_contentWidget;
    Wt::WContainerWidget* m_footerWidget;


};

} // namespace Widget

#endif // WIDGET_CONTAINERWIDGET_H
