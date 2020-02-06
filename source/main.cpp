#include <libgba-sprite-engine/gba_engine.h>
//#include "demo_scene.h"
#include "startscene.h"

int main()
{
    std::shared_ptr<GBAEngine> engine(new GBAEngine);// = std::make_shared<GBAEngine>();  //(new GBAEngine());

    //auto scene = std::make_shared<StartScene>(engine);//std::make_shared<DemoScene>(engine); //new DemoScene(engine);
    engine->setScene(new StartScene(engine)); //engine->setScene requires a Raw pointer thus using scene.get() to retrieve that raw pointer

    while(true)
    {
        engine->update();
    }


    return 0;
}