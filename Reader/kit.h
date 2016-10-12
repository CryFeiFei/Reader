//接口层所有的逻辑文档解析都在此接口
#ifndef KIT_H
#define KIT_H

class kit
{
public:
    kit(){}
    ~kit(){}

public:
    virtual int OpenFile() = 0;
    virtual int SaveFile() = 0;

};

#endif // KIT_H
