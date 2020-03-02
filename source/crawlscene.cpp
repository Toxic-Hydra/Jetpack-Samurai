#include "crawlscene.h"
#include "bgtest.h"


void CrawlScene::tick(u16 keys){
    // used to skip oopening crawl
    if(keys == KEY_A)
    {
        //ksad
        //sad
        engine->setScene(new DemoScene(std::move(engine)));

    }
    TextStream::instance().scroll(0,-x);
    x++;
    //TextStream::instance().scrollSpeed(0,-1);

}
void CrawlScene::load()
{
    engine->enableText();
    TextStream::instance().setText("text crawl here", 6, 7);
    //pressStart = "Press Start";
    engine->getTimer()->start();
    //crawlText=std::make_unique<Background>();
    x=1;
}
std::vector<Sprite *> CrawlScene::sprites()
{
    return {};
}

std::vector<Background *> CrawlScene::backgrounds()
{
    return {};
}