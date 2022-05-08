#include <iostream>
#include <fstream>
#include <vector>

void reverse(std::wstring& str);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Jako argument programu podaj nazwę pliku do odwrócenia" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        std::wifstream fileInput(argv[i]);
        
        if (!fileInput.good())
        {
            std::cerr << "Nie udało się otworzyć pliku" << std::endl;
            continue;
        }

        std::vector<std::wstring> lines;

        while (!fileInput.eof())
        {
            std::wstring line;

            try { getline(fileInput, line); }
            catch (std::exception& ex)
            {
                std::cerr << ex.what() << std::endl;
            }

            reverse(line);
            lines.push_back(line);
        }

        fileInput.close();

        std::wofstream fileOutput(argv[i]);

        for (int i = (int)lines.size() - 1; i >= 0; i--)
            fileOutput << lines[i] << std::endl;
        
        fileOutput.close();

        std::cout << "Odwrócono plik " << argv[i] << std::endl;
    }

    return 0;
}

void reverse(std::wstring& str)
{
    std::wstring reversed = L"";
    for (int i = (int)str.size() - 1; i >= 0; i--)
        reversed += str[i];
    str = reversed;
}
