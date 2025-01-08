#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Macro.h"

using namespace std;
using namespace sf;

typedef unsigned int u_int;

#define SLEEP(_duration) sleep(Time(_duration));

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE_X 20
#define TILE_SIZE_Y 20