#include <iostream>
#include <thread>

using namespace std;

void runInParallel() {
    cout<<"running in parallel"<<endl;
}

int main() {
    thread t(runInParallel);
    if (t.joinable()) t.join();
    return 0;
}
