#include <iostream>
void modifyValue(int *ptr);
int main()
{
    int *value_1=NULL;
    int *value=nullptr;
    // std::cout<<value<<std::endl;
    // std::cout<<*value<<std::endl;
    value = new int;// value allocate memory by default int pointer
    std::cout<<value<<std::endl;
    std::cout<<*value<<std::endl;
    int x=10;
    value=&x;
    std::cout<<&value<<std::endl;
    std::cout<<&x<<std::endl;
    std::cout<<value<<std::endl;
    std::cout<<*value<<std::endl;
    modifyValue(value);
    std::cout<<value<<std::endl;
    std::cout<<*value<<std::endl;
std::cout<<"########################################################################\n";
    int &ref=x;
    std::cout<<&ref<<std::endl;
    std::cout<<&x<<std::endl;
    std::cout<<ref<<std::endl;
    std::cout<<x<<std::endl;
    ref=30;
    std::cout<<&ref<<std::endl;
    std::cout<<&x<<std::endl;
    std::cout<<ref<<std::endl;
    std::cout<<x<<std::endl;


}
void modifyValue(int *ptr)
{
    *ptr=20;
}