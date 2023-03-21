#include "log.h"
#include "../display/displayserver.h"

int main()
{
    LOG("Engine main initialized.");
    DisplayArguments args = {
        800, 600, "DisplayServer"
    };
    DisplayServer display_server(args);
    while (!display_server.ShouldDisplayClose()) {
        display_server.PollDisplayEvents();
    }
    LOG("Engine display server closed.");
    return 0;
}