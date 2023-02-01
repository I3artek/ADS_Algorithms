//#include <iostream>
//#include "queue.h"
//
//int main(int argc, char**argv) {
//    //if the input is not a number, then N will be 0
//    //if there is no input - the same
//    int N = 0;
//    if(argc > 1)
//        N = atoi(argv[1]);
//    Queue q = Queue();
//    for(int i = 1; i < N + 1; i++)
//    {
//    }
//    for(int i = 1; i < N + 1; i++)
//    {
//        std::cout << q.Get() << " ";
//    }
//    return 0;
//}

#include <iostream>
#include <queue>
#include <chrono>

void BinaryNumbersGenerator(int n)
{
    std::queue<std::string> queue;

    queue.push("1");

    for (int i = 0; i < n; ++i)
    {
        std::string first = queue.front();
        queue.pop();

        std::cout << first << ", ";

        std::string second = first;

        queue.push(first.append("0"));
        queue.push(second.append("1"));
    }
}

int main() {
    int n;

    std::cout << "Hello, User!" << std::endl;
    std::cout << "Please, enter a number (positive integer) - N: ";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << "N = " << n << std::endl;

    std::cout << "Generated numbers:" << std::endl;
    //auto start = std::chrono::high_resolution_clock::now();
    BinaryNumbersGenerator(n);
    //auto stop = std::chrono::high_resolution_clock::now();
    //auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    //std::cout << std::endl << "Time elapsed: " << duration.count() << std::endl;

    return 0;
}
