//接口层所有的逻辑文档解析都在此接口
#ifndef KIT_H
#define KIT_H

#include <QString>
#include <QImage>

class Kit
{
public:
    Kit();
    virtual ~Kit(){}

public:
    // 内核初始化，必须要先调用
    virtual  int Init() = 0;


    virtual  QImage GetActruallyPageImage(int nPageNum) = 0;
    virtual  QSize GetActruallyPageSize(int nPageNum) = 0;
    virtual  int GetNumCount() = 0;
    // [in] dpi
    // [in] dpi
    // [in] x, y, w, h
    // [in] Rotation
    virtual  QImage GetPageImage(int nPageNum, int x=-1, int y=-1, int w=-1, int h=-1, int rotate = 0) = 0;

public:
    void  SetFileName(QString strFileName){ m_strFileName = strFileName;}

public:
    QString     m_strFileName;



};

#endif // KIT_H
