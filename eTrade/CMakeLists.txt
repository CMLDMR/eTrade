cmake_minimum_required(VERSION 3.26)

project(eTradeSystem LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

#ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Quick Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Quick Gui)



set(bsoncxx_DIR C:/Mongo/mongocxx-3.8/lib/cmake/bsoncxx-3.8.0)
set(mongocxx_DIR C:/Mongo/mongocxx-3.8/lib/cmake/mongocxx-3.8.0)


include_directories("${CMAKE_SOURCE_DIR}")

add_library(Bootstrap5ThemaKeys SHARED
    Bootstrap/Bootstrap5ThemaKeys.h
    Bootstrap/Bootstrap5ThemaKeys.cpp
    Bootstrap/inlinestyle.h
    Bootstrap/BootstrapThemaKeys_global.h
)
target_compile_definitions(Bootstrap5ThemaKeys PRIVATE BOOTSRAPTHEMEKEYS_LIBRARY)




add_library(MongoCore SHARED
    MongoCore/db.h
    MongoCore/db.cpp
    MongoCore/item.h
    MongoCore/item.cpp
    MongoCore/listitem.h
    MongoCore/listitem.cpp
    MongoCore/mongocore.h
    MongoCore/mongocore.cpp
    MongoCore/MongoCore_global.h
)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

target_include_directories(MongoCore PUBLIC "C:/Mongo/mongocxx-3.8/include")

target_link_directories(MongoCore PUBLIC "C:/Mongo/mongocxx-3.8/lib")

target_link_libraries(MongoCore PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)

target_compile_definitions(MongoCore PRIVATE MONGOCORE_LIBRARY)




add_executable(eTrade
  main.cpp
  MainApplication.cpp MainApplication.h
  Header/Widget.h Header/Widget.cpp
  Header/MenuBar.h Header/MenuBar.cpp
  Body/Slider.h Body/Slider.cpp
  Body/Section.h Body/Section.cpp
  Body/Feature.h Body/Feature.cpp
  Body/Product.h Body/Product.cpp
  Body/Body.h
  Body/Visitor.h Body/Visitor.cpp
  Body/CustomerReview.h Body/CustomerReview.cpp
  Body/LatestBlog.h Body/LatestBlog.cpp
  Footer/Footer.h Footer/Footer.cpp
)

target_link_libraries(eTrade PRIVATE Bootstrap5ThemaKeys)
target_compile_definitions(eTrade PRIVATE -DQT_NO_KEYWORDS)


add_executable(eTradePanel
  Qt/main.cpp
  Qt/MainWindow.h Qt/MainWindow.cpp Qt/MainWindow.ui
)





target_link_libraries(eTrade PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)



target_link_libraries(eTradePanel PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                          Qt${QT_VERSION_MAJOR}::Gui
                                          Qt${QT_VERSION_MAJOR}::Widgets
                                          Qt${QT_VERSION_MAJOR}::Quick)

target_link_libraries(eTradePanel PRIVATE MongoCore)


set(Wt_DIR C:/Wt-4.10.1-msvs2022-x64/lib/cmake/wt)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Wt-4.10.1-msvs2022-x64/lib/cmake/wt")
FIND_PACKAGE( Wt REQUIRED )
#include_directories(${Wt_INCLUDE_DIR})
target_include_directories(eTrade PUBLIC "C:/Wt-4.10.1-msvs2022-x64/include")
target_link_directories(eTrade PUBLIC "C:/Wt-4.10.1-msvs2022-x64/lib")
target_link_libraries(eTrade PRIVATE Wt WtHttp)

#include(GNUInstallDirs)
install(TARGETS eTrade
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
