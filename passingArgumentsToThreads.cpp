#include <iostream>
#include <thread>

using namespace std;

void runInParallel(int a , int b) {
    cout<<"sum of numbers is: "<<(a+b)<<endl;
}

int main() {
    thread t(runInParallel, 2, 3);
    if (t.joinable()) t.join();
    return 0;
}
