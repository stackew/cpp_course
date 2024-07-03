#include <iostream>
#include <fstream>
#include <string>

using fstream = std::fstream;

int main()
{
    fstream fWithLastLine, fWithoutLastLine;

    fWithLastLine.open("WithLastLine.txt", fstream::in);
    fWithoutLastLine.open("WithoutLastLine.txt", fstream::out);

    if (!fWithLastLine.is_open() || !fWithoutLastLine.is_open())
    {
        std::cout << "Что-то пошло не так!" << std::endl;
    }
    else
    {
        std::string InLine, TempLine;
        std::getline(fWithLastLine, InLine);

        while (!fWithLastLine.eof())
        {
            std::getline(fWithLastLine, TempLine);
            fWithoutLastLine << InLine << "\n";
            InLine = TempLine;
        }
        fWithLastLine.close();
    }
    fWithoutLastLine.close();

    return 0;
}