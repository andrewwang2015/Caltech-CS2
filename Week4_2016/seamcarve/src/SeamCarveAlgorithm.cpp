/*
 * SeamCarveAlgorithm.cpp
 * Defines the seam carving algorithm.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 */

#include "SeamCarveApp.hpp"

#define min(x, y)           ((x) < (y) ? (x) : (y))
 using namespace std;
 #include <iostream>


/**
 * @brief Peforms the seam carving algorithm.
 *
 * @param smap 2-d saliency map with width `w` and height `h`; can be
 * indexed by `smap[i][j]`
 *
 * @param w Width of the saliency map
 *
 * @param h Height of the saliency map
 */
unsigned int *DoSeamCarve(unsigned int **smap, int w, int h)
{
    /* TODO: Write this function! */

    unsigned int *seam = new unsigned int[h];

    /* A very bad seam carving algorithm... */
    for (int i = 0; i < h; i++)
    {
        seam[i] = 0;
    }

    int **arr = new int*[w];
	for (int i = 0; i < w; i++)
    	arr[i] = new int[h];

    for (int i = 0 ; i < w ; i++)
    {
    	arr[i][0] = smap[i][0];
    }

    for (int j = 1; j < h; j++)
    {
    	for (int i = 0 ; i < w; i++)
    	{
    		if (i == 0)
    		{
    			arr[0][j] = smap[0][j] + min(arr[0][j-1], arr[1][j-1]);		
    		}

    		else if (i == w - 1)
    		{
    			arr[i][j] = smap[i][j] + min(arr[i][j-1], arr[i-1][j-1]);	
    		}

    		else{
    			arr[i][j] = smap [i][j] + min(arr[i][j-1], min (arr[i-1][j-1], arr[i+1][j-1]));
    		}
    	}
    }

    int min1 = arr[0][h-1];
    int index;
    for (int i = 0 ; i < w; i++){
    	if (arr[i][h-1] < min1)
    	{
    		min1 = arr[i][h-1];
    		index = i;
    	} 
    }

    seam[h-1] = index;


    int small;

    for (int i = h-1; i > 0; i--)
    {
    	if (index == 0)
    	{
    		small = min(arr[0][i-1], arr[1][i-1]);
    		if (arr[0][i-1] == small)
    		{
    			index = 0;
    		}
    		else
    		{
    			index = 1;
    		}
    	}

    	else if (index == w-1)
    	{
    		small = min(arr[w-1][i-1], arr[w-2][i-1]);
    		if (arr[w-1][i-1] == small)
    		{
    			index = w-1;
    		}

    		else {
    			index = w-2;
    		}
    	}

    	else {
    		small = min (min (arr[index-1][i-1], arr[index][i-1]), arr[index+1][i-1]);
    		if (arr[index-1][i-1] == small){
    			index = index-1;
    		}

    		else if (arr[index][i-1] == small){
    			index = index;
    		}

    		else {
    			index = index+1;
    		}
    	}

    	seam[i-1] = index;
    }


    for (int i = 0; i < w; i++)
    	delete[] arr[i];
	delete[] arr;

    return seam;
}

