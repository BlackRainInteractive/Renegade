#include <Renegade/Renegade.hpp>

using namespace rge;

int main() {

    Application app;

    Window window = Window ();
    window.Create (WindowSettings ());

    Context context = Context ();
    context.Create (&window, ContextSettings ());

    app.RegisterWindow  (&window);
    app.RegisterContext (&context);

    while (app.IsRunning ()) {

        Event event;

        while (Event::PollEvents (event)) {

            switch (event.type) {

                case EventType::Close:
                case EventType::KeyDown:
                    app.Exit ();

                default:
                    break;
            }
        }
    }

    return 0;
}
