#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <ctime>    
#include <chrono>

char number[4];
int keysend;
int NumberCompare(int i);
void array(int i);

int main()
{
    system("TITLE RUST CODE CRACKER");
    system("color 0a");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 360, 600, TRUE);
    std::cout << "Good Luck Press [right arrow]\n";
    std::cout << "Num" << " | " << "Pin" << "  | " << "Time" << std::endl;
    for (int i = 1; i < 9996; i++)
    {
        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        while (!(GetKeyState(VK_RIGHT) & 0x8000))
        {
            Sleep(1);
        }
        array(i);
        if (GetKeyState(VK_RIGHT) & 0x8000) {
            for (int A = 0; A < 4; A++)
            {
                int KeyValue = NumberCompare(A);
                keybd_event(KeyValue, 0, KEYEVENTF_EXTENDEDKEY, 0);
                Sleep(1);
                keybd_event(KeyValue, 0, KEYEVENTF_KEYUP, 0);
                Sleep(100);
            }
            Sleep(100);
        }
        if(i<10)std::cout << i << ".  | " << number << " | " << std::ctime(&end_time);
        else{
            std::cout << i << ". | " << number << " | " << std::ctime(&end_time);
        }
    }
}

std::ifstream& GotoLine(std::ifstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

void array(int i)
{
    std::ifstream infile("numbers.txt");
    GotoLine(infile, i);
    infile.getline(number, 5);
    infile.close();
}

int NumberCompare(int i)
{
    if (number[i] == '0')
    {
        return 0x30;
    }else if (number[i] == '1')
    {
        return 0x31;
    }else if (number[i] == '2')
    {
        return 0x32;
    }else if (number[i] == '3')
    {
        return 0x33;
    }else if (number[i] == '4')
    {
        return 0x34;
    }else if (number[i] == '5')
    {
        return 0x35;
    }else if (number[i] == '6')
    {
        return 0x36;
    }else if (number[i] == '7')
    {
        return 0x37;
    }else if (number[i] == '8')
    {
        return 0x38;
    }else if (number[i] == '9')
    {
        return 0x39;
    }else
    return -1;
 }