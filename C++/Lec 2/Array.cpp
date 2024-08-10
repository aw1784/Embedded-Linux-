//  Array
#include<iostream>
#include<algorithm>
int main ()
{
    std ::vector<int >v={0,1,2,3,4,5,6,7};// the same as array but saved in heap
    int arr[]={8,10,3,9,5,6,7};
    for (int i=0; i<sizeof(arr)/sizeof(int); i++)
        std::cout<<*(arr+i)<<std::endl;
    std::cout<<"#######################################"<<std::endl;
    for (int value : arr)
    {
        std::cout<<value<<std::endl;
    }
    std::cout<<"#######################################"<<std::endl;
    std::sort(std::begin(arr), std::end(arr));
    for (int value : arr)
    {
        std::cout<<value<<std::endl;
    }
    std::cout<<"Max element = "<<*std::max_element(std::begin(arr),std::end(arr))<<std::endl;
    std::cout<<"#######################################"<<std::endl;
    // sort and lambda
    int offset=-5;
    std::sort(std::begin(arr), std::end(arr), [offset](int x,int y){return (x+offset)>y;});
    // decreprion of sort 
    for (int value : arr)
    {
        std::cout<<value<<std::endl;
    }
    
    return 0;
}