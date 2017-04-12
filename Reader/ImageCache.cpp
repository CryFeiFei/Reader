#include "ImageCache.h"

ImageCache::ImageCache()
{

}

ImageCache::~ImageCache()
{

}

bool ImageCache::getImage(int nPageNum, QImage &image)
{
    for (int i = 0; i < m_queue.size(); ++i)
    {
        if (m_queue[i].first == nPageNum)
        {
            image = m_queue[i].second;
            return true;
        }
    }
    return false;
}

bool ImageCache::insertImage(int nPageNum, QImage image)
{    
    if (m_queue.size() >= m_nMaxSize)
        m_queue.pop_front();

    m_queue.push_back(QPair(nPageNum, image));

    return true;
}
