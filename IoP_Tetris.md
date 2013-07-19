# Intension Oriented Programming

Zhang Gang
2013.07.13

##Why I write the program
I try to have a small example about IoP.

## Benefit
Very clear thinking flow.
No any uncessary service
Think single thing in same time.
What you think is what you get.
Put the domain model in mind. Refine them quickly.

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

12. Then I need a shape. 
    It tell me that I should have a factory to produce the shape.
    (pause the following action: to integrate immediately --
     it is OK, but I can bear integrate later with real shape)
    Then I want the shape to be appear in screen 

    OK, add a ShapeFactory. Then it tell me that memory leak. 
    so, I need to destory the shape after Game destory.
    I add a pointer named activeShape;

    Then it tell me that class Shape should not be in GraphcisController file.
    Move it to a new file now.
    OK, shape Factory was added


13. It's time to display shape in GUI
    Graphcis driver need a new API 'drawCell' to draw the block in special shape    Add the drawCell, and updated the integrated test cases.

  
14: How about to draw several real shape instead of a single cell? (to revealing the error in drawShape)
    Firstly, create a new test: testShape.cpp
    It drived a new class Cell, and make the Shape been implemented as a list
    And, now the drawCell in GUI can be beautiful. check it!

15. Make GUI display a bar. succeed.

16. Now the bar should can be moved down in case of a tick(); 
    But, TO MOVE A SHAPE SEEMS STRANGE.
    (add a value to every cell is not good. Also, transform of a shape is more complex if consider the postion information).
    It shows a key concept:  which object manage the placement of a shape?
    Game? Game seems is not the right object.
    Add a new object: Placement. It is not the object move. Placement can move.
    Add a UT for shape placement

17. Now change the Shape in Game to a placement.

18. Erase the area of Tetris in GUI to make it like move.
    Done
19. Then the shape can be moved left or right.

20. Then we try to add a key listener to accept input from player.
    Now I can move the block using keyboard.
    But, . The shape can move to any place. so we should have a 
    new class which could found it already moved to border.

21. Add collision detector interfaces.

22. (Because the Null object already play a role of collision detector stub,
     it is not necessary to mock the collision interface -- low risk).
    We implement the real colision detector immeidately.



