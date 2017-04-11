#ifndef IMAGE_CACHE_H
#define IMAGE_CACHE_H

#include <QImage>
#include <QMap>
#include <QPair>

#define ImageMap QMap<int, QImage>
#define ImageMapIter QMap<int, QImage>::iterator

class ImageCache
{
public:
    ImageCache();
    ~ImageCache();

private:
    ImageMap       m_map;
    int            m_nMaxSize;
public:
    bool getImage(int nPageNum, QImage &image);
    bool insertImage(int nPageNum, QImage image);

};

#endif // IMAGE_CACHE_H
