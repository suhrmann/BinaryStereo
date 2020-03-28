########LIBRAIRIES
LIBS_ffmpeg = -lm -lz -lpthread -lavformat -lavcodec -lavutil

DIR_opencv = /usr/local/opt/opencv@2/lib/pkgconfig/opencv.pc # or "opencv2" or "opencv"
LIBS_opencv = `pkg-config --libs $(DIR_opencv)`

LIBS_autres = -lpthread -ldl -lm

LIBS = $(LIBS_autres) $(LIBS_ffmpeg) $(LIBS_opencv)

########CONSTANTES
FLAGS_opencv = `pkg-config --cflags /usr/local/opt/opencv@2/lib/pkgconfig/opencv.pc`
CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -D__STDC_CONSTANT_MACROS $(FLAGS_opencv)
OBJS = main.o  CommonFunc.o  IStereoAlg.o  BinaryStereo.o

TARGET = main

########REGLES
$(TARGET): $(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.cpp 
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(LIBS)

all: $(TARGET)

clean: 
	rm -f $(OBJS) $(TARGET)
