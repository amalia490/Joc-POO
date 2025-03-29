#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <widemath.h>
#include "Map.h"
#include "Meniu.h"
#include "Banana.h"
#include "Game.h"
using namespace std;


class Obstacol {

};


class Miniona {

};

class buchetFlori {

};


int main()
{
    srand(time(0));
    Meniu meniu;
    //meniu.init(); 
    //meniu.initWindow();
   
    while (meniu.running()) {
            //meniu.rend();
            meniu.update();
        }

    return 0;
}

