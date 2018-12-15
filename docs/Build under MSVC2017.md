### Build under MSVC2017
For build project with MSVC2017 compiler you need to prepare a few things:
  - Install MSVC2017 64-bit compiler in Qt Maintenance Tool
  - Configure build settings to use MSVC2017 Desktop kit
  - If error "msvc-version.conf loaded but QMAKE_MSC_VER isn't set" occured - open directory with installed Qt tools (for instance C:\Qt\5.11.0\msvc2017_64\mkspecs\common ), then find and open file msvc-version.conf
  - In opened file - define the variable QMAKE_MSC_VER = 1909(or equal 1900) before macro isEmpty(QMAKE_MSC_VER)
  - Refresh project in Qt and try to build.
