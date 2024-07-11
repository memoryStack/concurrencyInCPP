#include <iostream>
#include <thread>

using namespace std;

class thread_guard {
    std::thread& t;
    public:
        explicit thread_guard(std::thread& t_):
            t(t_){}
        ~thread_guard() {
            if(t.joinable()) t.join();
        }
        thread_guard(thread_guard const&)=delete;
        thread_guard& operator=(thread_guard const&)=delete;
};

void runInParallel() {
    cout<<"running in parallel"<<endl;
}

int main() {
    thread t(runInParallel);
    thread_guard g(t);
    return 0;
}
