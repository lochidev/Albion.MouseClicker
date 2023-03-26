#include <iostream>
#include <thread>
#include <chrono>
#include "AlWin.h"
void ShowDesktop()
{
    while(true)
    {

        std::cout << "Sending 'Win-D'\n";
        INPUT inputs[4] = {};
        ZeroMemory(inputs, sizeof(inputs));

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_LWIN;

        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0x44;

        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = 0x44;
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = VK_LWIN;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

        UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        if (uSent != ARRAYSIZE(inputs))
        {
            std::cout << "SendInput failed: 0x%x\n" << HRESULT_FROM_WIN32(GetLastError());
        }
        std::cout << "Sent!";
    }
}
int main()
{
    //ShowDesktop();
    while (true)
    {
        using namespace std::chrono_literals;
        INPUT input1, input2, input3;
        input1.type = INPUT_MOUSE;
        input1.mi.dx = /*65535 / 2*/ 32767;
        input1.mi.dy = /*65535 / 2*/32767;
        input1.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
        input1.mi.mouseData = 0;
        input1.mi.dwExtraInfo = NULL;
        input1.mi.time = 0;
        SendInput(1, &input1, sizeof(INPUT));
        std::this_thread::sleep_for(1500ms);
        input2.type = INPUT_MOUSE;
        input2.mi.dx = 32767;
        input2.mi.dy = 24000;
        input2.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
        input2.mi.mouseData = 0;
        input2.mi.dwExtraInfo = NULL;
        input2.mi.time = 0;
        SendInput(1, &input2, sizeof(INPUT));
        std::this_thread::sleep_for(1500ms);
        input3.type = INPUT_MOUSE;
        input3.mi.dx = 30000;
        input3.mi.dy = 27000;
        input3.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
        input3.mi.mouseData = 0;
        input3.mi.dwExtraInfo = NULL;
        input3.mi.time = 0;
        SendInput(1, &input3, sizeof(INPUT));
        std::this_thread::sleep_for(1500ms);
    }
    return 0;
}
