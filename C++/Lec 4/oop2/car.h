#include <iostream>
class car
{
    private:
    int yearModel;
    std::string maker;
    std::string model;
    public:

    std::string getMake();
    std::string getModel();
    int getYearModel();
    void setMake(std::string m);
    void setModel(std::string m);
    void setYearModel(int y);
    car();  // default constructor
    car(std::string m, std::string h,int y);
};