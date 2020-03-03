#include "crawlscene.h"
#include "bgtest.h"


void CrawlScene::tick(u16 keys){
    // used to skip oopening crawl
    if(keys == KEY_A)
    {
        crawlspeed=0;
        finespeed=0;
        TextStream::instance().scroll(0,0);
        engine->setScene(new DemoScene(std::move(engine)));
    }
    TextStream::instance().scroll(0,finespeed);

    //contorlls speed of crawling text
    if(crawlspeed==16){
        crawlspeed=1;
        finespeed++;
    }
    //prevent scroll looping
    if(finespeed<75){
        crawlspeed++;
    }
}
void CrawlScene::load()
{
    engine->enableText();
    TextStream::instance().setText("Year 30AS. The City has", 2, 0);
    TextStream::instance().setText("become a battleground for", 3, 0);
    TextStream::instance().setText("samurai from all disciplines.", 4, 0);
    TextStream::instance().setText("Some use their power for", 5, 0);
    TextStream::instance().setText("good, and some use their", 6, 0);
    TextStream::instance().setText("power for evil.  During this", 7, 0);
    TextStream::instance().setText("turmoil, the evil ", 8, 0);
    TextStream::instance().setText("LEAGUE OF SAMURAI ENDING", 9, 0);
    TextStream::instance().setText("ROBOTS, has taken control.", 10, 0);
    TextStream::instance().setText("Only Jetpack Samurai, the", 11, 0);
    TextStream::instance().setText("mysterious jetpacked warrior,", 12, 0);
    TextStream::instance().setText("can bring peace in these", 13, 0);
    TextStream::instance().setText("unruly times.", 14, 0);
    TextStream::instance().setText("The keeper of the law,", 15, 0);
    TextStream::instance().setText("the deliverer of justice,", 16, 0);
    TextStream::instance().setText("and the courier of vengeance,", 17, 0);
    TextStream::instance().setText("Jetpack Samurai set out on", 18, 0);
    TextStream::instance().setText("their mission to thwart the", 19, 0);
    TextStream::instance().setText("evil organization.", 20, 0);
    TextStream::instance().setText("Press A to continue", 22, 0);
    engine->getTimer()->start();
    crawlspeed=1;
}
std::vector<Sprite *> CrawlScene::sprites()
{
    return {};
}

std::vector<Background *> CrawlScene::backgrounds()
{
    return {};
}