#include "car.h"
#include <iostream>
int main ()
{
    std::string m,h;
    car toyota("toyota","corolla",1960);
    car honda;
    std::cin>>m;
    honda.setMake(m);
    honda.setModel("Camry");
    honda.setYearModel(2020);
    std::cout <<"Car maker "<<toyota.getMake()<<"\n";
    std::cout <<"Car model "<<toyota.getModel()<<"\n";
    std::cout <<"Year model "<<toyota.getYearModel()<<"\n";
    // std::cin>>m>>h;
    // toyota.setModel(h);
    // toyota.setMake(m);
    std::cout <<"Car maker "<<honda.getMake()<<"\n";
    std::cout <<"Car model "<<honda.getModel()<<"\n";
    std::cout <<"Year model "<<honda.getYearModel()<<"\n";
    std::cout << "size of honda "<<sizeof(honda)<<"\n";

    return 0;
}
