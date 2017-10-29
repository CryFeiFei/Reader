#ifndef IMAGE_CACHE_H
#define IMAGE_CACHE_H

#include <QImage>
#include <QPair>
#include <QQueue>

#define ImageQueue QQueue<QPair<int, QImage>>

class ImageCache
{
public:
	ImageCache();
	~ImageCache();

private:
	ImageQueue     m_queue;
	int            m_nMaxSize;
public:
	bool getImage(int nPageNum, QImage &image);
	bool insertImage(int nPageNum, QImage image);

};

#endif // IMAGE_CACHE_H
