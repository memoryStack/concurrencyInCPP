#include <iostream>
#include <thread>

using namespace std;

/*
    after calling detach on a thread object, the thread that is associated with that
    thread object will be detached and will run in background. there is no way to
    talk to that thread, and all the control to manage that thread have been passed to
    C++ runtime so that it can claim all the resources allocated to it when the thread
    actually finishes.

    Uses to make a thread run in background:
        1. if you want a long-running thread whose lifetime is close to Application's
            lifetime.
        2. performing a background task such as monitoring the filesystem
        3. clearing unused entries out of object caches
        4. optimizing data structures
*/

void runInBackground() {
    cout<<"running in parallel in background"<<endl;
}

int main() {
    thread t(runInBackground);
    if (t.joinable()) t.detach();
    return 0;
}
