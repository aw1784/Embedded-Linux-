#include <iostream>
int main()
{

    unsigned char c;
    std::cout << "| Char |" "| ASCII |" << std::endl;
    for(int i=0;i<256;i++)
    {
        c = i;
        std::cout << "|  " <<static_cast<char>(c) << "  |  " <<i <<"  |"<< std::endl;
    }
    return 0;
}