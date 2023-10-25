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

    Wt::WDialog* createDialog(const std::string &title );
    void removeDialog( Wt::WDialog* mDialog );

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

    Wt::WContainerWidget* m_infoWidget{nullptr};

};

} // namespace Widget

#endif // WIDGET_CONTAINERWIDGET_H
