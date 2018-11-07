# Reader

## Describe

pdf reader like adobeReader. use Qt5 and poppler-qt5

## Compile

### Requirements

- QtVersion > 5.1
- poppler-qt5

### Win32

just run 
```
git clone https://github.com/CryFeiFei/Reader.git
```
and then 

- open the Reader.pro by QtCreator(MinGW)

you can build it

### Linux

#### Ubuntu

under *Ubuntu14.04 Ubuntu16.04 Ubuntu18.04* 

just run 
```
apt-cache search poppler-qt5
```
to search libpoppler-qt5-dev

```shell
sudo apt-get install pkg-config && libpoppler-qt5-dev
```

then,you can check up the dev package.

```shell
pkg-config --cflags poppler-qt5
```


### other desktop

you should build the poppler-qt5 by yourself

https://poppler.freedesktop.org/

after build the poppler-qt5, you can use it like Reader.pro
```c++
unix: PKGCONFIG += poppler-qt5
unix: CONFIG += c++11 link_pkgconfig
```
