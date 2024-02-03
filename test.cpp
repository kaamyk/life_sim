#include <iostream>
#include <vector>

int main( void ){
    std::vector<int*> v;

    for (unsigned int i = 0; i < 10; i++){
        v.push_back(new int(i));
    }

    for(std::vector<int*>::iterator i = v.begin(); i < v.end(); i++){
        std::cout << **i;
        if (**i == 4){
            delete *i;
            v.erase(i);
            i--;
        }
    }
    std::cout << std::endl;
    
    return (0);
}