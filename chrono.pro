TARGET=chronography
SOURCES=\
    main.cpp

QMAKE_CXXFLAGS +=  -Wall -O3 #-ffast-math -fopenmp
#QMAKE_LFLAGS += -fopenmp
CONFIG+=C++11
