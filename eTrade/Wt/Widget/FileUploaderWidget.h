#ifndef WIDGET_FILEUPLOADERWIDGET_H
#define WIDGET_FILEUPLOADERWIDGET_H

#include <Wt/WContainerWidget.h>
#include <Wt/WFileUpload.h>
#include <Wt/WSignal.h>
#include <Wt/Widget/ContainerWidget.h>

namespace Widget {

class FileUploaderWidget : public Widget::ContainerWidget /*, public DBClass*/
{
public:
    explicit FileUploaderWidget( const std::string &title = "Dosya Yükle" );

    /**
     * @brief isUploaded: Check file is Uploaded
     * @return
     */
    bool isUploaded() const;

    /**
     * @brief The FilterType enum: Selectable File Type
     */
    enum FilterType{
        Pdf,
        Image,
        DWG
    };

    /**
     * @brief setType: File Type
     * @param type: Pdf , Image
     */
    void setType( FilterType type );

    /**
     * @brief fileLocation: Location is FULL PATH
     * @return
     */
    std::string fileLocation() const;

    /**
     * @brief doocRootLocation: Location is Without docroot folder
     * @return
     */
    std::string doocRootLocation() const;

    /**
     * @brief Uploaded: Signal Triggered When File Uploaded
     * @return
     */
    Wt::Signal<Wt::NoClass> &Uploaded();

private:
    Wt::WFileUpload* mFileUploader;

    std::string mFileLocation;
    std::string mDoocRootLocation;

    bool mIsUploaded;

    Wt::Signal<Wt::NoClass> _Uploaded;

    FilterType mType;
};

} // namespace Widget

#endif // WIDGET_FILEUPLOADERWIDGET_H
