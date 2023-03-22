#include "win32_displayserver.h"

LRESULT CALLBACK Win32_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, CreateSolidBrush(RGB(0,0,0)));
        EndPaint(hwnd, &ps);
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

DisplayServer::DisplayServer(DisplayArguments args)
{
    win32_hInstance = GetModuleHandle(0);
    win32_wc.lpfnWndProc = Win32_WindowProc;
    win32_wc.hInstance = win32_hInstance;
    win32_wc.lpszClassName = L"DisplayServerClass";
    RegisterClass(&win32_wc);
        wchar_t* window_title = (wchar_t*)malloc(sizeof(wchar_t)*4096);
    MultiByteToWideChar(CP_ACP, 0, args.title, -1, window_title, 4096);
    win32_hwnd = CreateWindowEx(
        0, L"DisplayServerClass",
        window_title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, args.width, args.height,
        NULL,
        NULL,
        win32_hInstance,
        NULL
    );
    free(window_title);
    if (win32_hwnd == NULL) {
        perror("Error creating win32 window: ");
        exit(-1);
    }
    ShowWindow(win32_hwnd, SW_SHOW);
}

void DisplayServer::PollDisplayEvents()
{
    if (GetMessage(&win32_msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&win32_msg);
        DispatchMessage(&win32_msg);
        shouldClose = false;
    } else
    {
        shouldClose = true;
    }
}

void DisplayServer::RedrawWindow()
{
    UpdateWindow(win32_hwnd);
}

bool DisplayServer::ShouldDisplayClose()
{
    return shouldClose;
}

DisplayServer::~DisplayServer()
{
    DestroyWindow(win32_hwnd);
    UnregisterClass(L"DisplayServerClass", win32_hInstance);
}