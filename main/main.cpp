#include "log.h"
#include "../display/displayserver.h"

class Engine
{
private:
    DisplayArguments args;
    DisplayServer* display_server;
public:
    Engine()
    {
        LOG("Engine main initialized.");
        args = {
            800, 600, "DisplayServer"
        };
        display_server = new DisplayServer(args);
        LOG("Engine initialized.");
    }

    void mainLoop()
    {
        while (!display_server->ShouldDisplayClose()) {
            display_server->PollDisplayEvents();
        }
        this->~Engine();
    }

    ~Engine()
    {
        LOG("Engine display server closed.");
    }
};


int main()
{
    Engine* engine = new Engine();
    engine->mainLoop();
    return 0;
}