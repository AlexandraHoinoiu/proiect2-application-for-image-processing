QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    filter.h \
    gaussianfilter.h \
    mainwindow.h \
    meanfilter.h \
    medianfilter.h \
    rgbchannels.h \
    saltpeppernoise.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\include

LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_core430.dll
LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_highgui430.dll
LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_imgcodecs430.dll
LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_imgproc430.dll
LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_features2d430.dll
LIBS += C:\Users\Alex\Downloads\opencv-4.3.0-dldt-2020.1-vc16-avx2-debug\opencv\build\bin\libopencv_calib3d430.dll

# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/opencv-build/install
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320
