#pragma once

#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Macro.h"

using namespace sf;

typedef unsigned int u_int;

#define SLEEP(_duration) sleep(Time(_duration));
#define CAST(_type, _value) static_cast<_type>(_value)
#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE_X 20
#define TILE_SIZE_Y 20
#define DISPLAY(_text, _endl) cout << _text; \
								if(_endl) cout << endl;
