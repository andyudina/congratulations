#include "app.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    App app(argc, argv);
    return app.startGUI();
}
