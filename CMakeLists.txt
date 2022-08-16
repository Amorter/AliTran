cmake_minimum_required(VERSION 3.5)

project(MyProject1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES MyProject1_zh_CN.ts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    apioption.cpp
    apioption.h
    apioption.ui
    ReadWriteFile.h
    ReadWriteFile.cpp
    aliapi.cpp
    aliapi.h
    global.cpp
    global.h
    ${TS_FILES}
)



qt_add_executable(MyProject1
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/ssleay32.lib")
target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/libeay32.lib")
target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/libcurl.lib")
target_include_directories(MyProject1 PRIVATE "C:/Program Files (x86)/alibabacloud-oss-cpp-sdk/include")
target_link_libraries(MyProject1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyProject1 PRIVATE "C:/Program Files (x86)/alibabacloud-oss-cpp-sdk/lib/alibabacloud-oss-cpp-sdk-static.lib")

set_target_properties(MyProject1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS MyProject1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyProject1)
endif()
