#ifndef X11_DISPLAYSERVER_H
#define X11_DISPLAYSERVER_H
#include <X11/Xlib.h>
#include <X11/Xutil.h>

struct DisplayArguments
{
    int width, height;
    const char* title;
};

class DisplayServer
{
private:
    Display *disp;
    int screen;
    Window win;
    GC gc;
    XEvent event;
    Atom wmDeleteMessage;
    bool shouldClose;
    unsigned long blackPixel, whitePixel;
private:
    void RedrawWindow();
public:
    DisplayServer(DisplayArguments args);
    ~DisplayServer();
    void PollDisplayEvents();
    bool ShouldDisplayClose();
};

#endif