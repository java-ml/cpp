#include <utils.h>
#include <QDebug>
#include <QImage>
static HWND _WORKERW = nullptr;

inline BOOL CALLBACK EnumWindowsProc(_In_ HWND tophandle, _In_ LPARAM topparamhandle)
{
    HWND defview = FindWindowEx(tophandle, nullptr, L"SHELLDLL_DefView", nullptr);
    if (defview != nullptr)
    {
        _WORKERW = FindWindowEx(nullptr, tophandle, L"WorkerW", nullptr);
    }
    return true;
}



HWND Utils::GetWorkerW(){
    int result;
    HWND windowHandle = FindWindow(L"Progman", L"Program Manager");
    SendMessageTimeout(windowHandle, 0x052c, 0 ,0, SMTO_NORMAL, 1000,(PDWORD_PTR)&result);
    //遍历窗体获得窗口句柄
    EnumWindows(EnumWindowsProc,(LPARAM)nullptr);
     //显示WorkerW
    ShowWindow(_WORKERW,SW_HIDE);
    qDebug()<<"count"<<_WORKERW<<"----"<<windowHandle;
    return windowHandle;
}
