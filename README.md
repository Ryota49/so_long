# DESCRIPTION OF THE PROJECT

so_long is a project that will make you use the minilibx library, and expect you to create a 2D video game with a character, an exit and some collectible on your map. You have to display a map on a new screen, have some assets for collectible, characters, exit, grass and walls.
You can only have 1 character, 1 exit and atleast 1 collectible on your map to play it and the map must be surrounded by walls. Remember that a valid patern must exist to play the map and your map must be on a .ber file.

Here is an exemple of expected maps below :

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
P = Starting position of the character you will play.  
E = exit door of the game.  
C = Collectible that you need to take.  
0 = Grass that you can walk on.  
1 = Walls that you cannot go threw.  

## HOW TO PLAY

**1. Since this is a C project, you need to install gcc first if you don't have it to compile the program (minilibx-linux is using gcc) :**

> sudo apt-get install gcc -y

**2. Makefile**

After you have clone the repo, you can see there is two rules on the makefile, 1 for the mandatory part and 1 for the bonus. if you want to compile the mandatory part, type at the root of the repo :

> make 

if you want to compile the bonus part type at the root of the repo :

> make bonus

You can also type these two commands if you want to clean what you just created after typing make or make bonus :

> make clean  
> make fclean  

make clean = delete everything you have created with make or make bonus except so_long or so_long_bonus executable.

make fclean = delete everything you have created with make or make bonus with no exception.

**3. Execute the program**

After typing "**make**" on the terminal, an executable **so_long** has been created.
To execute the program and play a map, execute this file with a **.ber** map.  
Here is an exemple of how to execute a map and start playing :

> ./so_long maps/playable_subject_map.ber

If there is a valid patern, a valid structure of the map and it's a .ber format file on your map, then you should see your map display on a **new window**. If any error has been encountered, you can see the error on the terminal, it should help you.

**4. Controls**

Here is all the controls available in the program :

W = move up  
S = move down  
A = move left  
D = move right  
ESC = close the window and leave the program.

**5. How to play a bonus map**

To play with 1 ennemy patrol, you need to add a "M" on your map where you want. **My program only accept 1 ennemy max**, since the subject only requieres to make your character lose when you encounter an ennemy patrol on the same position.  
Here is a valid map for the bonus :

```
1111111111111
10M10000000C1
1000011111001
1P0011E000001
1111111111111
```

*reminder : Ennemy starting position count as a wall at the beginning, so make sure the starting position is not blocking the path for the verification of a valid path on the map.*

Here is an exemple of how to execute the bonus part after you have done make bonus :

> ./so_long_bonus maps/playable_subject_map2.ber

**6. How to win**

You need to take all the collectible on the map and then go to the exit door to win.
If you leave before that or goes threw an ennemy, you will lose.
At the end of the program, a message will display on the terminal saying "Victory !" or "You Lost !".  


## Contact

***Discord : ryota3544***  
***Mail : jean.monthioux49160@gmail.com***