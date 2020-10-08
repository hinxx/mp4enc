// Adapted from https://stackoverflow.com/questions/34511312/how-to-encode-a-video-from-several-images-generated-in-a-c-program-without-wri
// Taken from https://github.com/apc-llc/moviemaker-cpp
// Removed SVG and GTK stuff
// Removed the reader part

#ifndef MOVIE_H
#define MOVIE_H

#include <stdint.h>
#include <string>
#include <vector>

extern "C"
{
	#include <x264.h>
	#include <libswscale/swscale.h>
	#include <libavcodec/avcodec.h>
	#include <libavutil/mathematics.h>
	#include <libavformat/avformat.h>
	#include <libavutil/opt.h>
}

class MovieWriter
{
	const unsigned int width, height;
	unsigned int iframe;

	SwsContext* swsCtx;
	AVOutputFormat* fmt;
	AVStream* stream;
	AVFormatContext* fc;
	AVCodecContext* c;
	AVPacket pkt;

	AVFrame *rgbpic, *yuvpic;

	std::vector<uint8_t> pixels;

public :

	MovieWriter(const std::string& filename, const unsigned int width, const unsigned int height);

//	void addFrame(const std::string& filename);

	void addFrame(const uint8_t* pixels);

    void writeFrame(AVFrame *_frame);

	~MovieWriter();
};

#endif // MOVIE_H

