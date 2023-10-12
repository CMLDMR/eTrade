cmake_minimum_required(VERSION 3.14)

project(eTrade LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)



set(bsoncxx_DIR C:/Mongo/mongocxx-3.8/lib/cmake/bsoncxx-3.8.0)
set(mongocxx_DIR C:/Mongo/mongocxx-3.8/lib/cmake/mongocxx-3.8.0)


include_directories("${CMAKE_SOURCE_DIR}")


file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(eTrade
  ${HEADERS}
  ${SOURCES}
)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})




target_link_libraries(eTrade PRIVATE Qt${QT_VERSION_MAJOR}::Core )
target_link_libraries(eTrade PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)

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
