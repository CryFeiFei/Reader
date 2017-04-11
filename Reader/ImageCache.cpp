#include "ImageCache.h"

ImageCache::ImageCache()
{

}

ImageCache::~ImageCache()
{

}

bool ImageCache::getImage(int nPageNum, QImage &image)
{
    ImageMapIter it;
    it = m_map.find(nPageNum);

    if (it == m_map.end())
        return false;

    image = it.value();

    return true;
}

bool ImageCache::insertImage(int nPageNum, QImage image)
{
    return true;
}
