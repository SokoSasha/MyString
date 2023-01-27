build:
swig -python -c++ MyString.i
g++ -c -fpic MyString.cpp
g++ -c -fpic MyString_wrap.cxx -I/usr/include/python3.10
g++ -shared MyString.o MyString_wrap.o