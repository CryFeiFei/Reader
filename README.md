# Reader

#自己的个人网站 www.qtdoc.cn

## Qt，poppler，阅读器

use QT to creat a reader


# Reader在win下编译

windows平台下下来代码直接用QtCreator5.7打开就能编译通过


# Reader在linux下编译

### 编译poppler

### poppler在linux下编译方法


## Ubuntu

现在poppler在Linux官方的包一般可以找到

```shell
apt-cache search poppler-qt5
```
看看有没有linux的包

```shell
libpoppler-qt5-1 - PDF rendering library (Qt 5 based shared library)
libpoppler-qt5-dev - PDF rendering library -- development files (Qt 5 interface)
python3-poppler-qt5 - Python binding to Poppler-Qt5 C++ library (Python 3)
```
libpoppler-qt5-dev是poppler的包。直接安装

```shell
sudo apt-get install libpoppler-qt5-dev
```
安装成功之后可以用这个方式检查下
```shell
pkg-config --cflags poppler-qt5
```

这是最简单的方式了。如果没有的话只能去官方上下载最新的源代码自己安装了。

----

官方下载地址
https://poppler.freedesktop.org/

下载完之后解压
```shell
./configure
make
sudo make install
```
编译期间，根据不同的电脑安装自己对应的依赖包

然后再按照上边的步骤再安装

最后在Pro文件中添加这两行
```c++
unix: PKGCONFIG += poppler-qt5
unix: CONFIG += c++11 link_pkgconfig
```
