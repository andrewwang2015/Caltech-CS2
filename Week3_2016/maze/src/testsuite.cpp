/**
 * @file testsuite.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Performs tests of the CoordinateQueue and CoordinateStack classes.
 *
 * @section License
 * Copyright (c) 2014-2015 California Institute of Technology.
 * All rights reserved.
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
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#include <cstdio>
#include "CoordinateStack.hpp"
#include "CoordinateQueue.hpp"
#include <iostream>

int main()
{
    Coordinate c;
    CoordinateQueue *queue = new CoordinateQueue();
    CoordinateStack *stack = new CoordinateStack();
    Coordinate x;
    // stack -> stackitem -> coordinates -> x
	
    /* TODO: Test all the things! */
    cout << endl;
    cout << "Stack should be empty: expected (1) ...actual (" <<(*stack).is_empty()<<")" << endl;
    c = Coordinate(2,4);
    cout << "Pushing (2,4) onto stack." << endl;
    (*stack).push(c);
	cout << "Stack should not be empty anymore: expected (0) ...actual (" <<(*stack).is_empty()<<")" << endl;
    c = Coordinate(1,5);
    cout << "Pushing (1,5) onto stack." << endl;
    (*stack).push(c);

    c = Coordinate(3,7);

    cout << "Pushing (3,7) onto stack." << endl;
    stack-> push(c);
    c = Coordinate(stack->peek());
    
    cout << "Peeking at what's on top: expected (3,7)... actual (" <<c.x << "," << c.y <<")"<<endl;

    cout << "Popping stack. ";
    x = Coordinate((*stack).pop());
	cout << "Item popped is expected to be (3,7) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    c = Coordinate(stack->peek());

	cout << "Peeking at what's on top: expected (1,5)... actual (" <<c.x << "," << c.y <<")"<<endl;

	cout << "Popping stack. ";
    x = Coordinate((*stack).pop());
	cout << "Item popped is expected to be (1,5) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    c = Coordinate(stack->peek());
    cout << "Peeking at what's on top: expected (2,4)... actual (" <<c.x << "," << c.y <<")"<<endl;

    cout << "Popping stack. ";
    x = Coordinate((*stack).pop());
	cout << "Item popped is expected to be (2,4) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    cout << "Should be empty: expected (1) ...actual (" <<(*stack).is_empty()<<")" << endl;
	c = Coordinate(stack->peek());
	cout << "Stack is empty. A peek should return (-999,-999) ... actual (" <<c.x << ","<< c.y << ")"<< endl;


    x = Coordinate((*stack).pop());
    cout << "Popping from empty stack: should return (-999,-999) ... actual ("<< x.x << "," << x.y<<")" << endl;

    c = Coordinate(6,12);

    cout << "Pushing (6,12) onto stack." << endl;
    stack-> push(c);
    c = Coordinate(stack->peek());
    
    cout << "Peeking at what's on top: expected (6,12)... actual (" <<c.x << "," << c.y <<")"<<endl;
    cout << "Popping stack. ";
    x = Coordinate((*stack).pop());
    cout << "Item popped is expected to be (6,12) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    cout << "Stack should be empty: expected (1) ...actual (" <<(*stack).is_empty()<<")" << endl;
    cout << "Test of stack completed." << endl;

    cout << endl << endl;


    
    cout << "Queue should be empty: expected (1) ...actual (" <<(*queue).is_empty()<<")" << endl;
    c = Coordinate(6,12);

    cout << "Queuing (6,12) onto queue." << endl;
    queue-> enqueue(c);
    c = Coordinate(queue->peek());
    
    cout << "Peeking at what's on top: expected (6,12)... actual (" <<c.x << "," << c.y <<")"<<endl;
    c = Coordinate(2,4);
    cout << "Queuing (2,4) onto queue." << endl;
    (*queue).enqueue(c);
	cout << "Queue should not be empty anymore: expected (0) ...actual (" <<(*queue).is_empty()<<")" << endl;
    c = Coordinate(1,5);
    cout << "Queuing (1,5) onto queue." << endl;
    (*queue).enqueue(c);

    c = Coordinate(3,7);

    cout << "Queuing (3,7) onto queue." << endl;
    queue-> enqueue(c);
    c = Coordinate(queue->peek());
    
    cout << "Peeking at what's on top: expected (6,12)... actual (" <<c.x << "," << c.y <<")"<<endl;

    cout << "Dequeuing queue. ";
    x = Coordinate((*queue).dequeue());
	cout << "Item dequeued is expected to be (6,12) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    c = Coordinate(queue->peek());

	cout << "Peeking at what's on top: expected (2,4)... actual (" <<c.x << "," << c.y <<")"<<endl;

	cout << "Dequeing queue.";
    x = Coordinate((*queue).dequeue());
	cout << "Item dequeued is expected to be (2,4) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    c = Coordinate(queue->peek());
    cout << "Peeking at what's on top: expected (1,5)... actual (" <<c.x << "," << c.y <<")"<<endl;

    cout << "Dequeing queue. ";
    x = Coordinate((*queue).dequeue());
	cout << "Item dequeued is expected to be (1,5) ... actual (" <<x.x << "," << x.y <<")"<<endl;
	cout << "Dequeing queue. ";
    x = Coordinate((*queue).dequeue());
	cout << "Item dequeued is expected to be (3,7) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    cout << "Should be empty: expected (1) ...actual (" <<(*queue).is_empty()<<")" << endl;
	c = Coordinate(queue->peek());
	cout << "Queue is empty. A peek should return (-999,-999) ... actual (" <<c.x << ","<< c.y << ")"<< endl;


    x = Coordinate((*queue).dequeue());
    cout << "Dequeing from empty queue: should return (-999,-999) ... actual ("<< x.x << "," << x.y<<")" << endl;

    c = Coordinate(3,1);
    cout << "Queuing (3,1) onto queue." << endl;
    queue-> enqueue(c);
    cout << "Queue should not be empty anymore: expected (0) ...actual (" <<(*queue).is_empty()<<")" << endl;
    c = Coordinate(queue->peek());
    
    cout << "Peeking at what's on top: expected (3,1)... actual (" <<c.x << "," << c.y <<")"<<endl;
    cout << "Dequeing queue. ";
    x = Coordinate(queue->dequeue());
    cout << "Item dequeued is expected to be (3,1) ... actual (" <<x.x << "," << x.y <<")"<<endl;
    cout << "Queue should be empty: expected (1) ...actual (" <<(*queue).is_empty()<<")" << endl;
    cout << "Test of queue completed." << endl;
    cout << endl << endl;

    

    delete queue;
    delete stack;

    return 0;
}
