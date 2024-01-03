# Racecar CLI Game

This game was a course project for my class, "Programming with C++". It is a command-line interface game that has 3 different types of cars: the user's car, a speed car, and a handle car. The user's car will be controlled by x and y coordinate input from the user. The speed and handle cars are controlled by the computer through 2 different algorithms.

Algorithm one has the speed car race towards the finish line, but it does not care about the walls that get in its way. It will only look for the fastest way to get to the finish line and will continuously bump into walls and cars to try and get there.

Algorithm two has the handle car take the fastest route towards the finish, but it will avoid bumping into the walls and other cars. The handle car will not crash into anything and should win a majority of the time.

The computer controlled cars move around the track by looking at the _weights_ around them and finding the lowest one. The _weights_ are generated at the beginning of the game and are used by the speed and handle cars to manuever through the track. In order to ensure that the track weights can be generated automatically, the tracks themselves need to follow a certain format with the finish line represented with a 'F', the walls represented with a 'X', and the raceway represented with a 'T'.

The weights start at the finish line with the number 0, and increase value as they get farther from the finish. Here is an image showing how this works.

![alt text](https://media.cheggcdn.com/media/e17/e17f13fa-f7bd-4df7-a383-2d526714fc50/php8l2gpv)
