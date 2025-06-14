#include <iostream>
#include <thread>

using namespace std;

int main() {
    const auto processor_count = std::thread::hardware_concurrency();
    cout<<"processor count: "<<processor_count<<endl;
    return 0;
}

/*
    system_profiler SPHardwareDataType | grep "Cores"

    for my mac the above command and the C++ code returns same number of cores.
    

*/
