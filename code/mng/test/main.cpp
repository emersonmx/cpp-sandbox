#include <iostream>

#include <mng/engine.h>
#include <mng/main_loop.h>

using namespace std;

int main()
{
    mng::Engine engine;
    mng::DefaultMainLoop loop{engine};
    engine.setMainLoop(loop);
    engine.run();
    return 0;
}
