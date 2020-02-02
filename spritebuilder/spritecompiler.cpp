#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

/**********************************************************************
*
* @Author:  Ivan Lopez
* @Date:    1/30/20
* Converts all sprites in Sprites folder to c code through a  grit call
* Then combines them all into a combined.c for engine purposes.
*
***********************************************************************/


int main()
{
    auto path = std::filesystem::current_path();
    if(std::filesystem::exists(path.append("Sprites")))
    {
        std::ofstream file("combined.h", std::ios::in |std::ios::out | std::ios::app);
        std::string argument = " ";
        std::string argumentStorage = " ";
        
        //Iterate through images to help construct arguments for grit.
        for (const auto& entry : std::filesystem::directory_iterator{path})
        {
            if(entry.path().extension().string() == ".png")
                argument += path.string() + "\\" + entry.path().filename().string() + " ";
                argumentStorage += path.string() + "\\" + entry.path().stem().string() + ".c ";
        }

        
        //System call to cmd so we can use grit. Cool epic.
        argument = "grit\\grit.exe" + argument + "-ftc -pS -gB8 -O " + path.string() + "\\shared.c" + " -o " + argumentStorage;
        std::cout << argument << std::endl;
        std::system(argument.c_str());

        //Now we create our combined.c

        for(const auto& entry : std::filesystem::directory_iterator{path})
        {
            try
            {
                if(entry.path().extension().string() == ".c")
                {
                    //Could use some improving in here to remove all comments from c code. If i care enough.
                    std::ifstream ofile{entry.path()};
                    file<< ofile.rdbuf() << std::endl;
                    std::cout<< entry.path().filename().string() << std::endl;
                    ofile.close();
                }
            } 
            catch (const std::exception& e)
            {
                std::cout <<"Error accessing files" << entry.path().string()<<std::endl;
            }
        }

        file.close();
    }
    std::cout << "Current path: " << path << std::endl;


   return 0;
}