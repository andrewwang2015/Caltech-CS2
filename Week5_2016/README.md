Part 0: Debugging

Yes, there is something wrong with the algorithm implemented here for dfs. This algorithm does not account for possible loops because there lacks a structure keeping track of which nodes have been visited. In our depth first search implemented for the maze, we had a 2D array "visited" that kept track of locations/ nodes that have been visited. This ensures that once we add a location once, we do not add it again. If we lacked such a structure to keep track of visited locations, we could keep on pushing and popping the same set of locations, creating a loop.

Similarly, for this example, it is quite possible that we have a set of nodes so that node 1 is connected to node 2 which is connnected to node 1, creating a cycle. To avoid processing a node more than once, we need to implement a structure such as a boolean visited array, so that for the above example, if we move to node 2, we test to see if node 1 has already been visited (which should be true) so we know node 1 does not have to be tested again, avoiding a cycle.



Part I: Short Answer

1. A MST (minimum spanning tree) is a spanning tree whose weight is the smallest compared to weights of any other spanning tree. The tree must be connected with all vertices/ nodes by a subset of all the edges such that the sum of edge weights is minimal. 

So, it has to be a tree (any two vertices are connected by exactly one path). The graph is undirected, so the edges have no orientation. 
It has to be spanning, meaning it contains all the vertices of the original graph. And it has to be minimum, meaning the sum of the edge costs for this tree is less than edge costs of all other spanning trees. 

2. We choose the edge with the smallest weight and the vertex connected to the other end of this edge. We have to do this because if we were to pick another edge, then those trees would contain an edge that is bigger than the minimum edge coming out from the first vertex and thus violate the minimum requirement of MSTs.

3. For each additional step, we pick the minimum edge that has 1 vertex in tree and 1 vertex outside the tree. Doing so will add an additional vertex to our tree that minimizes the weight of the path. We repeat this process until all the vertices are in the tree. Once all the vertices are in the tree, we know it is spanning.

4. We first choose an edge with minimum weight that connects two different trees and we add this edge. This will reduce the total number of trees by 1 and because we choose the edge with minimum weight each time, we know that that the edge path we took is the smallest possible between the two trees. We keep doing this until we only have one tree left (our final MST).

Outline (Kruskal's algorithm): Psuedocode

Create set of trees, where each vertex is its own tree
Create set of all edges in graph

DO until there is only one tree left
	Remove the edge with minimum weight in the set of edges 
	IF edge connects two different trees
		combine the two trees on the end of this edge into one tree
	ELSE
		remove the edge



Part II:

1. It would make sense to choose the neighbor that is the shortest distance away from you. 

2. When we pick our first vertex, we update all the adjacent vertices by making it the distance value between these vertices and the first vertex. We remove the first vertex from the set of unvisited vertices. We find the adjacent vertex to the first vertex with the smallest distance value and remove that vertex from the set of unvisited vertices. We then look at the adjacent vertices to the vertex that was just removed from the unvisited list (we call x). In general, for every adjacent vertex y to x, if sum of the distance from x to y and value of x is smaller than the current value of y, then we update the distance value of y. Once we consider all adjacent vertices to the current vertex (x), we remove the current vertex (x) from the unvisited list. Then, out of the unvisited nodes, we then select the node that is marked with the smallest value and set that as the new x and repeat this process until there are no more unvisited vertices. At each step, we only look at adjacent vertices that are unvisited. In addition, each node/vertex that is removed from the unvisisted list will store its parent node/vertex. This will be helpful for traceback. We are guaranteed to get the shortest path because at each step, we find the node that is shortest in path distance thus far, until we reach the final destination. 

3. We are done when all the vertices will have been visited. To derive the path we want, we look at the destination node and follow the destination nodes' parents up to the starting node. This is why we keep track of each node's parent. With this, the traceback is not difficult and the shortest path is easy to derive. 

Outline (Djikstra's Algorithm): Psuedocode

	FOR each vertex in graph
		initialize distance of this vertex to be infinity
		initialize the previous vertex to this vertex to be null
	END FOR

	Initialize distance from source to source to be zero

	WHILE the set of all vertices is not empty
		remove vertex in set with smallest distance value
		FOR each neighbor of the removed vertex
			IF (distance value of removed vertex + distance between removed vertex and neighbor) < distance value of neighbor
				SWAP
				Set previous vertex to to be the removed vertex
			END IF
		END FOR
	END WHILE

	Return set of previous vertices



FEEDBACK:

1. I don't consider myself that experienced. I had programmed in Java and Python for a couple of years before, but CS1 was my first main course on programming. I am following this course, although I do feel like the course is moving rather quickly. To keep up, I've gone in for tutoring sessions and office hours pretty much every week. 

2. The hardest part about C++ is how much control the programmer has. A lot of the stuff other programming languages do behind the scenes for you (memory deallocation, cleanup, etc.) is not done in C++. This increase in control however has led to frustrating error messages (usually something regarding memory leaks). I think it would have been better if the "boot camp" for C++ was a bit longer. For me, it was rather difficult to learn and grasp a high-level language in less than two weeks. 

3. I spent about 5 hours on this set (would have spent more but CS21 final). I would say most of the time was spent learning the "ins and outs" of the C++ language and attempting to learn what is going on with the stars and starmap. It took me far less time understanding the basic concepts (probably 70/30). 

4. The data structures assignment took me the most time and the dynamic programming took me the least time. The most difficult so far has been the data structures assignment because of all the technicalities it introduced (nodes, etc.). The data structures assignment also took the longest to debug which contributed to its difficulty and length to complete. 

5. I personally didn't find the outlines too helpful and would often dive into coding before making an outline. This being said, I think making an outline is good practice and if nothing else, ups the self esteem of CS2 students struggling to get any points they can at 4 am in the morning.

6. I thought this assignment was interesting but definitely on the harder end of the spectrum. There was a lot of writing involved which was good for points, and I found it very time consuming trying to learn the database we were working out of for the assignment. I didn't think the concepts were too difficult to grasp, but the implementation was definitely hard to do. I think more explicit instructions and hints/suggestions would have definitely been more helpful. The fact that this week's assignment was done with relation to a stars database makes it much more difficult to code because we need a thorough understanding of all the structures and classes regarding stars, starmaps, etc. In all, I didn't think this assignment was particuarly useful for me as a programmer, but a simplified version of this assignment would have probably been more helpful.

7. Yes, I did attend. As in general, the recitations are very helpful for the assignments because they target more on how the assignment should be done as opposed to the lectures which introduce the concepts behind the assignments. The TAs were prepared to present and answer questions, and as of now, I don't think they need to be improved much.

8. Yes, I did attend the lectures. They are useful for introducing the concepts and the lecturer was clear and prepared. As of now, these lectures do not need to be vastly improved.

9. Yes, I knew this course would be vital for practical CS and I like how this course incorporates a lot of programming. It is a lot of work, as I expected, but I think there would be great benefit in going a bit slower. In the last few assignments, I felt rushed and think I did not grasp the concepts as well as I would have liked. In addition, more suggestions/ tips on the homework sets would save a lot of time and prevent frustration. Often, the assignments are so open ended that it takes significant time and research to understand how we do this or that in C++, let alone code the entire solution.




