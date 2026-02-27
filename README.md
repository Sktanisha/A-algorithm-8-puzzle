Here, we have given an initial configuration and a goal configuration. Using A*, we have to solve the initial configuration to the goal configuration by the minimum number of moves. 
First, we generate all possible configurations of the next possible moves and calculate the Manhattan distance. After calculating the distance, we keep the distance in a priority queue.
Then we pop the top element (minimum distance). After check if the configuration is the goal state or not, if yes, we break the loop; if not, we do the procedure again. 
