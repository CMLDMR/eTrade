#include "FileUploaderWidget.h"
#include <Wt/WPushButton.h>
#include <Wt/WProgressBar.h>
#include <Wt/WApplication.h>

#include <Bootstrap/Bootstrap5ThemaKeys.h>
#include <Bootstrap/inlinestyle.h>

#include <filesystem>


using namespace Wt;

namespace Widget {



FileUploaderWidget::FileUploaderWidget(const std::string &title)
{
    mIsUploaded = false;

    auto fileUploaderContainer = this->addWidget(std::make_unique<WContainerWidget>());
//    fileUploaderContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(150,170),this->getRandom(170,190),this->getRandom(200,220)));
//    fileUploaderContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    fileUploaderContainer->setMargin(10,Side::Top|Side::Bottom);
    //    fileUploaderContainer->setWidth (WLength("100%"));

    mFileUploader = fileUploaderContainer->addWidget(std::make_unique<WFileUpload>());
    auto progresBar = fileUploaderContainer->addWidget(std::make_unique<WProgressBar>());
    mFileUploader->setFileTextSize(6000); // Set the maximum file size to 2048 kB.
    mFileUploader->setMargin(10, Wt::Side::Right);
    mFileUploader->setFilters("application/pdf");
    mFileUploader->setMultiple(false);
    mFileUploader->setProgressBar(progresBar);

    mFileUploader->fileTooLarge().connect([=] {
        this->showInfo("Dosya Boyutu Fazla Büyük. Max: 6MB Olmalı",ContainerWidget::InfoType::error);
    });

    Wt::WPushButton *uploadButton = fileUploaderContainer->addWidget(std::make_unique<Wt::WPushButton>(title));
    uploadButton->setMargin(10, Wt::Side::Left | Wt::Side::Right);

    uploadButton->clicked().connect([=] {
        mFileUploader->progressBar()->setValue(0);
        mFileUploader->upload();
        mFileUploader->enable();
        mFileUploader->setHidden(false);
    });

    mFileUploader->uploaded().connect([=] {

        auto list = mFileUploader->uploadedFiles();

        for( const auto &item : list )
        {
            std::filesystem::path dosyaYoluNesnesi(item.spoolFileName());

            std::filesystem::path tempFolder(wApp->docRoot()+"/tempfile");
            if ( ! ( std::filesystem::exists(tempFolder) && std::filesystem::is_directory(tempFolder) ) ) {
                std::filesystem::create_directory(tempFolder);
            }

            mFileLocation = std::string("tempfile/")+item.clientFileName();
            mFileAbsoluteLocation = wApp->docRoot()+"/"+mFileLocation;
            std::filesystem::path hedefDosyaYolu(mFileAbsoluteLocation);

            try {
                std::filesystem::copy(dosyaYoluNesnesi,hedefDosyaYolu,std::filesystem::copy_options::overwrite_existing);

                mIsUploaded = true;
                _Uploaded.emit(NoClass());

            } catch (const std::filesystem::filesystem_error& e) {
                showInfo(std::string("Dosya Yükleme Hatası: ")+e.what(),ContainerWidget::InfoType::error);
                mIsUploaded = false;
            }


        }

    });
    setType (Image);

}

bool FileUploaderWidget::isUploaded() const
{
    return mIsUploaded;
}

void FileUploaderWidget::setType(FileUploaderWidget::FilterType type)
{
    mType = type;

    switch (mType) {
    case Pdf:
        mFileUploader->setFilters ("application/pdf");
        break;
    case Image:
        mFileUploader->setFilters ("image/*");
        break;
    case DWG:
        mFileUploader->setFilters ("application/acad");
        break;
    default:
        break;
    }
}

std::string FileUploaderWidget::fileLocation() const
{
    return mFileLocation;
}

std::string FileUploaderWidget::fileAbsoluteLocation() const
{
    return mFileAbsoluteLocation;
}

Signal<NoClass> &FileUploaderWidget::Uploaded()
{
    return _Uploaded;
}

} // namespace Widget
