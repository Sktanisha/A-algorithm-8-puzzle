Here, we have given an initial configuration and a goal configuration. Using A*, we have to solve the initial configuration to the goal configuration by the minimum number of moves. 
First, we generate all possible configurations of the next possible moves and calculate the Manhattan distance. After calculating the distance, we keep the distance in a priority queue.
Then we pop the top element (minimum distance). After check if the configuration is the goal state or not, if yes, we break the loop; if not, we do the procedure again. 

Findings:
•	A* algorithm is complete as it found the optimal solution if it exists.
•	A* is one of the best heuristic search techniques.

Limitations:  
•	This algorithm is complete if the branching factor is finite and every action has a fixed cost.
•	The performance of A* search is dependent on the accuracy of the heuristic algorithm used to compute the function h(n).

