# Intension Oriented Programming

Zhang Gang
2013.07.13

##Why I write the program
I try to have a small example about IoP.

##Progress

1. I start from a Game class. It is the first one I know.
   what the program should be? 

   I draw a GUI about Tetris, like what I have played in past.
   It likes as following:
   < add a diagram, manually drawing>

   Then, I think a game class firstly should have an init class.
   It can draw the GUI I mentioned above.

2. so I write down a Unit test:

   Game.init expect ->
      draw a main frame
      draw a box for tetris blocks
      draw a box for next block
      the initial score is 0
      the initial speed is 0

   It help me to create an interface. I called it 'paint'.

   Till now, we produced an interface, and a Game use the interface.
   But the interface have not been implemented.

3. After a short while, I feel that the name 'paint' and the method
   is mis-match. It tell me that the concept should be mine further.
   Game should not directly call a draw interface. 
   Better to have a 'GraphcisController'.

   so, I refine the UT as following:
   IPainter --> IGraphcisController
4. It seem that the draw very block in Game is too detail. 
   Better to tell GraphcisController to init the GUI. 
   so Refine them to combine several methods into one.

5. Now I can consider how to implement the controller.
   Firstly I add an empty method.

   In the step, I feel that it is not necessary to write UT first
   Because there is no new interface to be impelented. 

   To find what interface I need, I try to implement the controller

   Soon, I found that I need an interface which can really call the computer
   to draw the graphcis.

   I named it graphcis driver.

6. I try to write down the interface of graphcis driver.
   It contains drawBox, writeText, 

7. Still no UT. But now I am consider a simple graphcis driver. 
   I used the ncurses library in linux. 

8. I am not familar with the ncurses. 
   I write a UT (not automatically) to test how to draw using the ncurses.
   It is clear for me on the tasks. 
   I need to draw a box, and write some text.

   OK, now I know how the ncurse use coordinate -> x is the vertical dimension
                                                -> y is the horizal dimension
   I also found the the size in vertial is larger than horizonal, so I decided that use 2 chars in horizonal as unit 1.

9. Now I can draw on ncurse library. so it is the right time to make a skeleton of the game.
   I integrated the Game -> GraphcisController -> NcursesGraphcisDriver.

10. After integrate all of them, I adjusted the position of each block. and I found that I can draw two more blocks: score block and speed block.

=========================================================
OK, now I can demo a empty tetris interface, although there is no any block ===.

==========================================================

11. The next step is: what will happen when a game start? 
The player will push start key, and a block will appear on top 
of the tetris area.

    Then I wrote down the first test case: 
    when game start (player press 'start' key)
    a shape should appear.

    It help to discover some new interfaces:
    -> GraphcisController need a new API: drawShape

 