#include "x11_displayserver.h"

DisplayServer::DisplayServer(DisplayArguments args)
{
    shouldClose = false;
    disp = XOpenDisplay((char*)0);
    screen = DefaultScreen(disp);
    blackPixel = BlackPixel(disp, screen);
    whitePixel = WhitePixel(disp, screen);
    win = XCreateSimpleWindow(disp, DefaultRootWindow(disp), 0, 0, args.width, args.height, 5, whitePixel, blackPixel);
    
    XSetStandardProperties(disp, win, args.title, args.title, None, NULL, 0, NULL);

    XSelectInput(disp, win, ExposureMask);

    wmDeleteMessage = XInternAtom(disp, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(disp, win, &wmDeleteMessage, 1);

    gc = XCreateGC(disp, win, 0, 0);

    XSetBackground(disp, gc, blackPixel);
    XSetForeground(disp, gc, whitePixel);
    XClearWindow(disp, win);
    XMapRaised(disp, win);
}

void DisplayServer::PollDisplayEvents()
{
    XNextEvent(disp, &event);
    if (event.type == Expose && event.xexpose.count == 0) {
        RedrawWindow();
    }
    if (event.type == ClientMessage) {
        if (event.xclient.data.l[0] == wmDeleteMessage) {
            shouldClose = true;
        }
    }
}

void DisplayServer::RedrawWindow()
{
    XClearWindow(disp, win);
}

bool DisplayServer::ShouldDisplayClose()
{
    return shouldClose;
}

DisplayServer::~DisplayServer()
{
    XFreeGC(disp, gc);
    XDestroyWindow(disp, win);
    XCloseDisplay(disp);
}
