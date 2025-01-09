#include <iostream>
#include "buffer.hpp"

int main() {
        std::cout << "Please enter buffer capacity: ";
        size_t x;
        std::cin>>x;
        sb::CircularBuffer<int> buffer(x); 
        int y;
        do {
            std::cout <<"----------------------------\n";
            std::cout << "1. Add element to buffer\n";
            std::cout << "2. Remove element from buffer\n";
            std::cout << "3. Display buffer\n";
            std::cout << "4. View last element\n";
            std::cout << "0. End\n";
            std::cout << "Please choose option: ";
            std::cin >> y;
            std::cout <<"----------------------------\n";
     
            switch (y){
                case 1:
                    int z;
                    std::cin >> z;
                    buffer.push(z);
                    break;
                case 2:
                    std::cout << "Removed element: " << buffer.pop() <<"\n";
                    break;
                case 3:
                    if (buffer.size()==0){
                        std::cout << "Buffer is empty\n";
                    } else {
                        buffer.print();
                        std::cout << "Is buffer full?: " << (buffer.isFull() ? "Yes" : "No") << "\n";
                        std::cout << "Current size: " << buffer.size() << " elements\n";
                    }
                    break;    
                case 4:
                    std::cout << "Last element: " << buffer.front() << "\n";
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Please choose again\n";
            }
        } while (y != 0);
        return 0;
}