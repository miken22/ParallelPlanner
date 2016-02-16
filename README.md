# ParallelPlanner
An openMP implementation for an automated planner for tasks represented using the SAS+ formulation.
Developed by Michael Nowicki for COSC 449 Honours Thesis, 2015.

Some of the code, specifically for representing the components of the planning task, were highly based on the work done by Malte Helmert
and others who built Fast-Downward (available at http://www.fast-downward.org/. See The fast downward planning system by Malte Helmert in
Journal of Artifical Intelligence Research, 2006 for more details).
 
This program is built to use the output of their SAS+ Translator program and their preprocessor was already optimized to use this output 
I followed their preprocessors code to load and build the components of the planning tasks and have acknowledged their work in each
header file. 

## Installing the Planner

- Navigate to the directory where the planner is on your device and compile the program by running the `./build.sh` script. If the build
is successful the executable Planner file should appear in the directory.

## Running the Planner

- To run the planner use the following command:

```
./Biuld/Path/Planner ./Build/Path/tests/test_name.sas -s (0-3) -h (0,2,3) [-p (1,...)] [-c] [-g]
```

The first flag (-s) selects the planner type by entering an integer from 0-3 after the flag. The options are as follows:
Currently there are:
0 - Standard A* Search
1 - Sequential Iterative Deepening
2 - Parallel A* with a queue and stack
3 - Parallel Iterative Deepening using Stacks

The second flag (-h) is used to pick the heuristic for the search. There are currently 4 heuristics that can be used, with the last one being a blind heuristic. The choices are as follows:
0 - Original Causal Graph Heuristic
2 - Constrained Causal Graph Heuristic with Full Actions
3 - Blind

The third flag (-p) is required for the parallel search algorithms. Enter an integer N and the program will run with 2^N threads.

The fourth flag (-g) is used to indicate that the program should protect goal variables, ie if a variable has achieved a goal state and the operator changes the value of the variable we do not use the operator. This may result in solvable tasks being rendered unsolvable.
