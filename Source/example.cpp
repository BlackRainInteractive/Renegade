#include <Renegade/Core/Application/Application.hpp>

using namespace rge;

int main () {

    Application_New application_new = Application_New ();
    application_new.Initialize ();

    EventManager* eventManager = application_new.GetEventManager ();

    Event event;

    while (application_new.Update ()) {

        while (eventManager -> PollEvents (event)) {

            switch (event.eventType) {

                case ET_AppInit:
                    break;

                case ET_AppShutdown:
                    break;
            }
        }
    }

    application_new.Shutdown ();

    return 0;
}
