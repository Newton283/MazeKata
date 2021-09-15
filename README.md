# MazeKata

Author: Evan Newton

This project was written in C++ using Visual Studio and uses GoogleTest as the unit testing framework.
To build the project, open the solution file in Visual Studio and Build Solution.

To run the project, run MazeKata\Release\MazeKata.exe

To run the unit tests, run MazeKata\Release\MazeKataTest.exe (best viewed when run from cmd line)





Analysis Story 1

Here are a few mazes that would stump the MazeSolver:

(1)
```
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%~~##@~~%%
%~%%%~%%%%
%~%%%%%%%%
%~%%%%%%%%
%~%%%%%%%%
```
(2)
```
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%%%#%%%%%%
%~~#@~~%%%
%~%~%%%%%%
%~%%%%%%%%
%~%%%%%%%%
%~%%%%%%%%
```
(3)
```
%%%%#%%%%%
%~~~##@#~%
%~~~##~%~%
%~~~##~%~%
%~~~##~%~%
%~~~##~%~%
%~~~##~%~%
%~~~##~%~%
%~%%%%%%~%
%~%%%%%%%%
```

Analysis Story 2

When designing my MazeSolver, my first thought was to have it move the max direction possible in any given
cardinal direction. After a little more thinking I realized that it would easily skip over hallways that 
branch off a straight path. From there I decided to move a single space at a time and move in any direction 
with an opening. While writing user story 2, I realized that if it moves down a hallway I can't have "open"
directions on both sides or it may start going in reverse. This prompted me to write out the path as it 
moved, "closing" up the space. With this logic alone, the solver solved user stories 2,3, and 4 with no 
change to the code. 

I did expect that a backup would be needed. The path would effectively restrict open movements and could 
result in dead ends with no available moves. Originally I thought I would need a backup at user story 2.
Luckily I wrote the move such that the solver did a winding path up and down through the room. The main
issue with the backup is that it will only backup until a free space is available. This will lead to 
repeating mistakes. Beyond repeating mistakes, the backup could use more memory to backup further if 
mistakes have been repeated. A new tile character could be added for tiles/paths to never traverse again.
This would allow the backup function to expand, most likely having to use the stored path stack. My 
original intention was to used the stored path stack to aid in backing up multiple spaces. My lastTile 
pointer made backing up simpler than having to use the path stack. 

Analysis Story 3

I would break the problem down into the following stories:
(1) Expand the Maze to find the starting/finish points and return them.
	-New start/finish points will have to accommodate 3 tiles.
	-Multiple starts/finishes can be added to the maze.
		-As I have written the Maze object, it is not self aware enough to know what a valid exit
		 is beyond 3 consecutive points on the top/bottom row. Starting to "hunt" further inward
		 for valid maze is not the job of the maze object.
	-Remove invalid start/finishes
		-If the maze solver can't find a solution from a start or finish, the maze solver could
		 tell the maze that a particular solution isn't valid. This is assuming the maze solver
		 can start from either side.
(2) Solve a non rotational maze
	-Expand the MazeSolver's size to a 1x3 "ship"
	-Expand GetOpenDistance functions to allow distance available for the entire 1x3 ship. This will 
	 allow the ship to traverse in any direction.
	-Rework Move as needed. Pathing/backup logic may change.
```
	%%~%%
	%%~%%
	%%~%%
	%~~~%
	%~~~%
	%~~~%
	%%%~%
	%%%~%
	%%%~%
```
(3) Solve rotational maze with invalid exit in non rotation area
	-Implement rotation function
	-Implement recursion and/or branching path with move command at each 3x3 square. Be careful not to 
	 run both at the same time as to not break display properties and integration testing method. Be 
	 careful not to branch infinitely in larger rooms, like a 4x4.



