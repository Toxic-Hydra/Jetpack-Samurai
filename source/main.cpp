#include <libgba-sprite-engine/gba_engine.h>
#include "demo_scene.h"

int main()
{
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto scene = new DemoScene(engine);
    engine->setScene(scene);

    while(true)
    {
        engine->update();
    }


    return 0;
}