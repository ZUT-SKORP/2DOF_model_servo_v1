#include <windows.h>
#include <stdio.h>
#include <iostream>

int main() {
    HANDLE h_Serial;
    LPCWSTR COM_name = L"COM9";
    h_Serial = CreateFileW(COM_name, GENERIC_WRITE, 0, 0, OPEN_EXISTING,
                      FILE_ATTRIBUTE_NORMAL, 0);
    if (h_Serial == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            // serial port not found. Handle error here.
        }
        // any other error. Handle error here.
    }
    DCB dcbSerialParam = {0};
    dcbSerialParam.DCBlength = sizeof(dcbSerialParam);

    if (!GetCommState(h_Serial, &dcbSerialParam)) {
        std::cout << "GetCommState" << std::endl;
    }

    dcbSerialParam.BaudRate = CBR_9600;
    dcbSerialParam.ByteSize = 8;
    dcbSerialParam.StopBits = ONESTOPBIT;
    dcbSerialParam.Parity = NOPARITY;

    if (!SetCommState(h_Serial, &dcbSerialParam)) {
        std::cout << "SetCommState" << std::endl;
    }

    COMMTIMEOUTS timeout = {0};
    timeout.ReadIntervalTimeout = 60;
    timeout.ReadTotalTimeoutConstant = 60;
    timeout.ReadTotalTimeoutMultiplier = 15;
    timeout.WriteTotalTimeoutConstant = 60;
    timeout.WriteTotalTimeoutMultiplier = 8;

    if (!SetCommTimeouts(h_Serial, &timeout)) {
        std::cout << "SetCommTimeouts" << std::endl;
    }

    short n = 8;
    char sBuff[] = "hej";
    DWORD dwRead = 0;
    if (!WriteFile(h_Serial, sBuff, n, &dwRead, NULL)) {
        std::cout << "WriteFile" << std::endl;
    }

    

    CloseHandle(h_Serial);
    return 0;
}
