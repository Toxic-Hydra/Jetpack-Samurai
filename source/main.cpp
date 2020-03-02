#include <libgba-sprite-engine/gba_engine.h>
// #include "demo_scene.h"
#include "start_scene.h"

int main()
{
    std::shared_ptr<GBAEngine> engine = std::make_shared<GBAEngine>();  //(new GBAEngine());

    // auto scene = std::make_shared<StartScene>(engine); //new DemoScene(engine);
    // engine->setScene(scene.get()); //engine->setScene requires a Raw pointer thus using scene.get() to retrieve that raw pointer
    engine->setScene(new StartScene(engine));

    while(true)
    {
        engine->update();
    }


    return 0;
}