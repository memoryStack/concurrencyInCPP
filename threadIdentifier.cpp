#include <iostream>
#include <thread>

using namespace std;

void runInParallel() {
    cout<<"spawned thread ID: "<<(this_thread::get_id())<<endl;
    cout<<"running in parallel"<<endl;
}

int main() {
    thread t(runInParallel);
    
    cout<<"main thread ID: "<<(this_thread::get_id())<<endl;

    if (t.joinable()) t.join();
    return 0;
}
