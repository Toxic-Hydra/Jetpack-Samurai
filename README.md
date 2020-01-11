## Getting Started
in order to setup the dev environment make sure you have installed [DevkitPro](https://devkitpro.org/) specifically the GBA installation.
Also install [mGBA](https://mgba.io/) a usefull emulator for debugging.

If you want to work in an environment identical to mine then you will need to install visual studio code and the following plugins: 
[Visual Studio ARM](https://marketplace.visualstudio.com/items?itemName=dan-c-underwood.arm)
[C/C++ plugin](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
[C/C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global)

in your visual studio code go to prefferences/settings and under C/C++ change intellisense Mode to gcc
also under IntelliSense Engine change default to tag parser (theres a bug in intellisense that forces us to use this.)
You should then be able to open this repo under vs code. F5 to run debug.

## Special Thanks
for this project we're using a few other open source technologies:
[GBA Sprite Engine by Wouter Groeneveld](https://github.com/wgroeneveld/gba-sprite-engine)
[TONC: The best gba programming resource and fantastic library](https://www.coranac.com/projects/tonc/)
[And Jamie D Stewart's fantastic GBA game template](https://github.com/JamieDStewart/GBA_VSCode_Basic)

## Wait what even is this repo?
We're a group of Computer Science: Game Design students at UCSC working on our final capstone project.
For our final project we decided to work on a GBA game, Eventually this repo will evolve as we begin working on it.