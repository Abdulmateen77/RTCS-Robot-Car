#include <stdlib.h>
#include <initio.h>
#include <curses.h>

//======================================================================
//line_follower():
//Simple program to test infrared line sensors:
//Drive along a black line. The black line is bordered on both sides
//with a white line to ensure contrast for the line sensors.
//======================================================================
void line_follower(int argc, char *argv[]) 
{
  int ch = 0;
  int irL,irR;  //status of infrared sensors
  int lfL,lfR;  //status of line sensors

  //Drive forward initially
  initio_DriveForward();

  while (ch != 'q') {
    mvprintw(1, 1, "%s: Press 'q' to end program", argv[0]);

    // Read sensor values
    irL = initio_IrLeft();
    irR = initio_IrRight();
    lfL = initio_IrLineLeft();
    lfR = initio_IrLineRight();

    //Obstacle detected by infrared sensors
    if (irL != 0 || irR != 0) {
      mvprintw(3, 1, "Action 1: Stop (IR sensors: %d, %d)     ", irL, irR);
      initio_DriveForward(0); // Stop
    }
    //No obstacle ahead, focus on line following
    else if (lfL == 0 && lfR == 0) { 
      mvprintw(3, 1, "Action 2: Straight (Line sensors: %d, %d)    ", lfL, lfR);
      initio_DriveForward(70);
    }
    //Car is too much on the right
    else if (lfR != 0) {
      mvprintw(3, 1, "Action 3: Spin left (Line sensors: %d, %d)    ", lfL, lfR);
      initio_SpinLeft(100); //Spin left at Full speed
    }
    //Car is too much on the left
    else if (lfL != 0) {
      mvprintw(3, 1, "Action 4: Spin right (Line sensors: %d, %d)    ", lfL, lfR);
      initio_SpinRight(100); //Spin right at Full speed
    }
    //Lost the line
    else {
      mvprintw(3, 1, "Lost my line (Line sensors: %d, %d)        ", lfL, lfR);
      initio_DriveReverse(70); //Stop and reverse
    }

    //Read user input
    ch = getch();
    if (ch != ERR)
      mvprintw(2, 1, "Key code: '%c' (%d)", ch, ch);
    refresh();  //curses
  } //while

  return;
}

//======================================================================
//main(): initialization of libraries, etc
//======================================================================
int main(int argc, char *argv[])
{
  WINDOW *mainwin = initscr();  //curses: init screen
  noecho();                    //curses: prevent the key being echoed
  cbreak();                    //curses: disable line buffering 
  nodelay(mainwin, TRUE);       //curses: set getch() as non-blocking 
  keypad(mainwin, TRUE);        //curses: enable detection of cursor and other keys

  initio_Init(); //initio: init the library

  line_follower(argc, argv);

  initio_Cleanup();  //initio: cleanup the library (reset robot car)
  endwin();           //curses: cleanup the library
  return EXIT_SUCCESS;
}
