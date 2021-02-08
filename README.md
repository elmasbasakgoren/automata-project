# automata-project
FORMAL LANGUAGE AND
AUTOMATA THEORY PROJECT 



	Project Aim
The main objective of the project is to solve the TSP problem with 3 different methodologies. These methodologies are the nearest and divide and conquer algorithm. There are different results with these applied algorithms.



	Algorithms Results

	Nearest Neighbor Algorithms: In order to implement the application, we need 2 main things: knowledge of previously visited places and knowledge of the nearest place to go. A function called findIndexOfNearestNonVisitedPoint() was created to reach points that were not visited, and this function provides that the visited points are not considered to use in the next iteration. The shortest path calculated in the Point.cpp class was implemented in a function called nearestNeighbour(), which continued with that path as the shortest path was calculated.

Length: 40.526

Time: Very close to 0


	Divide and Conquer Algorithms: The method used in this algorithm is similar to nearest. The difference is that divide and conquer calculates 24 of the 48 points separately and gives the results by creating a single circle. The rest of the progress methodology is the same as nearest.
 
Length:55.939
      Time: Very close to 0


	Conclusion
To conclude, from these 3 algorithms, whose aim is to find the shortest path, we can say that the most appropriate and optimized working algorithm is the nearest neighbor algorithm. In order for us to evaluate it in terms of time, we had to have more than 48 points. The divide and conquer and nearest neighbor algorithms ran fast, so they came out as 0ns. Hovewer, when we check the bigOh notation, we can see that divide and conquer algorithm should work faster. to sort out the algortimas, greedy will be slow among them.







