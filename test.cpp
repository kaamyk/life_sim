#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>

int main( void ){
   std::vector<int> v;

   for (unsigned char i = 0; i < 5; i++){
    v.push_back(i);
   }
   std::cout << v.size() << std::endl;
   v.clear();
   std::cout << v.size() << std::endl;

    return (0);
}