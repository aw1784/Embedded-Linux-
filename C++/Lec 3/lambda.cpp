#include<functional>
#include <iostream>
int main()
{
    int x=10,y=20,z=30;
    auto lambda =[/*capture*/](/*parmetres*/int x,int y,int z)
    {
        //body
        return x + y + z;
    };


    std::cout << "Sum: " << lambda(x, y,z) << std::endl;
    std ::cout << "Size of lambda "<<sizeof(lambda)<<std::endl;


    [](int x,int y,int z,int lambda (int ,int,int))
    {
        std::cout << "Sum: " << lambda(x, y,z) <<std::endl;
    
    }(x,y,z,lambda);
    [=]()
    {
        std::cout << "Sum: " << lambda(x,y,z) <<std::endl;
    }(); // the same as the function before
     
    auto lambda_1 =[z](int x,int y)//mutable
    {
        // z=10;       //error we can avoid it by using mutable
        return x + y + z;

    };//if we add mutable after the parameters we can change offest in side the lambda but don't change out of it 
    [&]()//take all by reference
    {
        x=50,y=100,z=150;
        std::cout << x<<std::endl;
        std::cout << y<<std::endl;
        std::cout << z<<std::endl;
        std::cout << "Sum: " << lambda_1(x,y)<<std::endl;//the capture(z)of lambda_1 will be added by its old value=20 evem if I put multiple to lambda_1 or not 
    }();
    std::cout << x<<std::endl;
    std::cout << y<<std::endl;
    std::cout << z<<std::endl;
    
    //intialise a pointer to lambda
    int(*pf)(int x,int y,int z)= [/*capture*/](/*parmetres*/int x,int y,int z)
    {
        //body
        return x + y + z;
    };


    std::cout<<pf(x,y,z)<<std::endl;

    int(*pf_2)(int x,int y,int z)= lambda;
    
    std::cout<<"pointer to lambda(pf_2)= "<<pf_2(x,y,z)<<std::endl;

    // int(*pf_4)(int x,int y,int z)= lambda_1; //error due to captured lambda
    std::function<int(int,int)>pf_3=lambda_1;
    std::cout<<"pointer to lambda_1(pf_3)= "<<pf_3(x,y)<<std::endl;

    
    return 0;
    
}
// #include <iostream>
// int main()
// {
//   int x = 10;
//   int y = 20;
//   int z = 30;
    
//   class __lambda_5_18
//   {
//     public: 
//     inline /*constexpr */ int operator()(int x, int y, int z) const
//     {
//       return (x + y) + z;
//     }
    
//     using retType_5_18 = int (*)(int, int, int);
//     inline constexpr operator retType_5_18 () const noexcept
//     {
//       return __invoke;
//     }
    
//     private: 
//     static inline /*constexpr */ int __invoke(int x, int y, int z)
//     {
//       return __lambda_5_18{}.operator()(x, y, z);
//     }
    
    
//     public:
//     // /*constexpr */ __lambda_5_18() = default;
    
//   };
  
//   __lambda_5_18 lambda = __lambda_5_18{};
//   std::operator<<(std::cout, "Sum: ").operator<<(lambda.operator()(x, y, z)).operator<<(std::endl);
//   std::operator<<(std::cout, "Size of lambda ").operator<<(sizeof(lambda)).operator<<(std::endl);
    
//   class __lambda_12_5
//   {
//     public: 
//     inline /*constexpr */ void operator()(int x, int y, int z, int (*lambda)(int, int, int)) const
//     {
//       std::operator<<(std::cout, "Sum: ").operator<<(lambda(x, y, z)).operator<<(std::endl);
//     }
    
//     using retType_12_5 = void (*)(int, int, int, int (*)(int, int, int));
//     inline constexpr operator retType_12_5 () const noexcept
//     {
//       return __invoke;
//     };
    
//     private: 
//     static inline /*constexpr */ void __invoke(int x, int y, int z, int (*lambda)(int, int, int))
//     {
//       __lambda_12_5{}.operator()(x, y, z, lambda);
//     }
    
    
//     public:
//     // /*constexpr */ __lambda_12_5() = default;
    
//   } __lambda_12_5{};
  
//   __lambda_12_5.operator()(x, y, z, lambda.operator __lambda_5_18::retType_5_18());
    
//   class __lambda_18_20
//   {
//     public: 
//     inline /*constexpr */ int operator()(int x, int y) const
//     {
//       return (x + y) + z;
//     }
    
//     private: 
//     int z;
    
//     public:
//     __lambda_18_20(int & _z)
//     : z{_z}
//     {}
    
//   };
  
//   __lambda_18_20 lambda_1 = __lambda_18_20{z};
    
//   class __lambda_24_5
//   {
//     public: 
//     inline /*constexpr */ void operator()() const
//     {
//       ((x = 50) , (y = 100)) , (z = 150);
//       std::cout.operator<<(x).operator<<(std::endl);
//       std::cout.operator<<(y).operator<<(std::endl);
//       std::cout.operator<<(z).operator<<(std::endl);
//       std::operator<<(std::cout, "Sum: ").operator<<(lambda_1.operator()(x, y)).operator<<(std::endl);
//     }
    
//     private: 
//     int & x;
//     int & y;
//     int & z;
//     __lambda_18_20 & lambda_1;
    
//     public:
//     __lambda_24_5(int & _x, int & _y, int & _z, __lambda_18_20 & _lambda_1)
//     : x{_x}
//     , y{_y}
//     , z{_z}
//     , lambda_1{_lambda_1}
//     {}
    
//   } __lambda_24_5{x, y, z, lambda_1};
  
//   __lambda_24_5.operator()();
//   std::cout.operator<<(x).operator<<(std::endl);
//   std::cout.operator<<(y).operator<<(std::endl);
//   std::cout.operator<<(z).operator<<(std::endl);
//   return 0;
// }
