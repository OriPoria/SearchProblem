# ex4
# Search algorithm solver

# Description
This project is in C++ and deals with getting a problem from client, calculate the solution, and send it back 
to the client. We developed a program the first create a server, it can be a serial server, that can recive in any specific
time one client, calculate the problem and send him the solution, or can open a parallel server that can get up to 10
clients in parallel. In this first milestone of the project, we focus on specific problem, we called it "Matrix Problem"
which we expect to get from the client a string that represents a martix, that every value is a cost of each square, and 
last two lines represnts starting point and goal point, and our program calcualets for the client the shortest path to 
get from the starting point to the goal point with minimum cost. In order to implement the best algorithm that will solve 
this problem we have tested the different solutions of 4 different algorithms. The conclusion of the expirement is the 
the A star search algorithm is the best and we decided to implement it to solve this problem.

# Usage
You can use this code as client namely connect as a client to the server, if you have a matrix with costs for each square, and the program will find for you the shortest
path between to points on the matrix, you need to send the matrix line by line, saperted with ',', the each value represents the cost, at the end of 
every line you need to write '\n', and the last to line are the positions of the stating square and the goal sqare. If the cost of one square is -1, it
is like a block that you cannot pass. The values of costs should be only integers. at the end of your messages to the server, you need to send the string 
"end\n" to know the this is the end of the file. the program calculats the solutions by its algorithm or if we have already got this specific problem, we 
take the solution from the cache file manager, that holds all the old porblems and solutions we have had.
If you want to run this code as the sever, you can choose in the calss Boot, in its main method, if you want to run the program with a parallel server, or 
with a serial server. You can also change the type of Searcher that will solver the problem. 
The program is very easy to extend because you can add and new type of searching shortest path problem, that the server wiil get a different input, and will
create a new problem, and stil the machanizm that solve the problem. and returns the solution to the client will remain as it is.

 
 **pin points of project**
 - Cache Manager :class that holds all the problems and thier solutions in files and can 
		  return a solution to the client in O(1), if we have already got the same input of the problem.
 - Search Client Handler: class that maneges each client, getting the input, checks if the solution is in the files and 
			  returns the solution if it is there, else, solve the problem, and calls again the cache maneger
			  to save the new solution.

# to run our code
- prepare a text file of matrix, each sqare represnts the cost, 
  at the end of every line '\n' and values seperated with ','.
  last two lines are the starting point and end point at the last line - 'end\n'.

# Links
- for github: //https://github.com/oripo1312/ex4
