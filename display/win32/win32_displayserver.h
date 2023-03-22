#ifndef WIN32_DISPLAYSERVER_H
#define WIN32_DISPLAYSERVER_H
#define UNICODE
#include <windows.h>

struct DisplayArguments
{
    int width, height;
    const char* title;
};

class DisplayServer
{
private:
    HINSTANCE win32_hInstance;
    WNDCLASS win32_wc = { };
    MSG win32_msg = { };
    HWND win32_hwnd;
    bool shouldClose;
private:
    void RedrawWindow();
public:
    DisplayServer(DisplayArguments args);
    ~DisplayServer();
    void PollDisplayEvents();
    bool ShouldDisplayClose();
};

#endif