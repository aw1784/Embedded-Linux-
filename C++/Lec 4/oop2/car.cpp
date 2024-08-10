#include "car.h"
void car::setMake(std::string m)
{
    maker=m;

}
void car::setModel(std::string m)
{
    model=m;

}
std::string car::getMake()
{
    return maker;
}
std::string car::getModel()
{
    return model;
}
void car:: setYearModel(int y)
{
    yearModel=y;
}
int car:: getYearModel()
{
    return yearModel;
}
car::car()
{
    maker="Unknown";
    model="Unknown";
    yearModel=0;
    std::cout << "Hello\n";
}
car::car(std::string m, std::string h,int y):maker(m),model(h),yearModel(y)
{

}