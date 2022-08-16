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

file(GLOB SRC_FILES "./*.cpp")
file(GLOB HEAD_FILES "./*.h")
file(GLOB TS_FILES "./*.ts")
file(GLOB UI_FILES "./*.ui")
set(PROJECT_SOURCES
    ${SRC_FILES}
    ${HEAD_FILES}
    ${TS_FILES}
    ${UI_FILES}
    resources.qrc
    README.md
)



qt_add_executable(MyProject1
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

qt_add_translations(MyProject1 TS_FILES zh.ts)



target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/ssleay32.lib")
target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/libeay32.lib")
target_link_libraries(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/lib/x64/libcurl.lib")
target_include_directories(MyProject1 PRIVATE "C:/Users/11452/Desktop/aliyun-oss-cpp-sdk/third_party/include")
target_include_directories(MyProject1 PRIVATE "C:/Program Files (x86)/alibabacloud-oss-cpp-sdk/include")
target_include_directories(MyProject1 PRIVATE "C:/Program Files/alibabacloud-sdk/include")
target_link_libraries(MyProject1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyProject1 PRIVATE "C:/Program Files/alibabacloud-sdk/lib/alibabacloud-sdk-core.lib")
target_link_libraries(MyProject1 PRIVATE "C:/Program Files/alibabacloud-sdk/lib/alibabacloud-sdk-alimt.lib")
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
