# About
This is a project I am working on where I create a game engine.

# Platforms supported:
Linux and Windows are both supported.

# Dependencies:
For Linux it is:
- X11
For Windows it is:
- Windows.h and `gdi32.lib`

# Building:
You can change the compiler in the CC flag in the makefile to what ever you want. For example: 
```
CC=clang++
```
If you want to build with multithreading use the `-j` compiler flag.