/**
* @file common.h
* @author Ben Yuan <<byuan@caltech.edu>>
* @version 1.0
* @date 2012-2014
* @copyright see License section
* 
* @brief Defines common functions and variables.
* 
* @section License
* Copyright (c) 2012-2014 California Institute of Technology.
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met: 
* 
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer. 
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution. 
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those
* of the authors and should not be interpreted as representing official policies, 
* either expressed or implied, of the California Institute of Technology.
* 
*/

#ifndef COMMON_H
#define COMMON_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <utility>

#ifndef NO_GFX
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glut.h>
#else
typedef double GLdouble;
typedef float GLfloat;
typedef int GLint;
#endif

#include <sqlite3.h>

#include "error.hpp"

#define WIDTH 800
#define HEIGHT 600

#endif
