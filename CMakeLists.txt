cmake_minimum_required(VERSION 3.5)

project(IK VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(glfw3 REQUIRED CONFIG)
find_package(glm REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)




if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(IK
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        renderer/renderer.h renderer/renderer.cpp
        game.h game.cpp
        renderer/camera.h renderer/camera.cpp
        renderer/objects/cone.cpp renderer/objects/cone.h renderer/objects/cube.cpp renderer/objects/cube.h renderer/objects/cylinder.cpp renderer/objects/cylinder.h renderer/objects/OBJ_Loader.h   renderer/objects/sphere.cpp renderer/objects/sphere.h renderer/objects/trimesh.cpp renderer/objects/trimesh.h
        renderer/scenedata.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET IK APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(IK SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(IK
            ${PROJECT_SOURCES}
        )
    endif()
endif()

add_subdirectory(glm)

target_link_libraries(IK PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(IK PRIVATE glm)
target_link_libraries(IK PRIVATE glfw)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.IK)
endif()
set_target_properties(IK PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS IK
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(IK)
endif()
