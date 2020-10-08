FFMPEG_LIBS =   libavformat                        \
                libavcodec                         \
                libswresample                      \
                libswscale                         \
                libavutil                          \

CFLAGS += -Wall -g -O0
CFLAGS := $(shell pkg-config --cflags $(FFMPEG_LIBS)) $(CFLAGS)
LDLIBS := $(shell pkg-config --libs $(FFMPEG_LIBS)) $(LDLIBS)

CFLAGS := $(shell pkg-config --cflags x264) $(CFLAGS)
LDLIBS := $(shell pkg-config --libs x264) $(LDLIBS)

all: test1

%.cpp: movie.h

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

test1: main.o writer.o
	$(CXX) $^ -o $@ $(LDLIBS)

clean:
	rm -f test1 *.o
