# Final Project Proposal

## Group Member:

Steven Luo

# Intentions:

Ideally, the project will be a recreation of ultimate tic-tac-toe, in which:
* Each cell of the outer board has an inner board.
* To win an outer board cell, the corresponding inner board must be won.
* The inner board cell selection determines which inner board is played in the next turn.

[Wikipedia](https://en.wikipedia.org/wiki/Ultimate_tic-tac-toe)

However, the priority is to create normal tic-tac-toe before moving on to the ultimate version.

If I determine I can't make the ultimate version in time, I'll add a server-client piping functionality to make up for the loss of forking.

# Intended usage:

The terminal will display the board(s), with designations for each cell included.

An example of a designation is: 00-02 for top left outer cell, top right inner cell.

The players are prompted for a designation at each turn.

# Technical Details:

* Semaphore - To switch between Player 1 and Player 2
* Shared memory / Allocating memory - To store which inner board the next player can play in
  * Two ints: Row and column
* File management - To change and store board data
  * Structs of char designation and int player marker
  * Inner board: 9 lines of 9 structs
  * Outer board: 3 lines of 3 structs
* Processes - To split the management of inner and outer boards
  * Outer board program: Setup, display, inner board selection using shared memory
  * Forked inner board program: Player prompts, data setting, win determination

Win Condition will be checked at each turn through brute force.

# Intended pacing:

NORMAL PHASE
* Wed 01/08 - Player prompts + Board file start + Basic board display (extremely barebones)
* Fri 01/10 - Semaphores for turns + Board file manipulation
* Mon 01/13 - Win condition detection

ULTIMATE PHASE
* Wed 01/15 - Forking for inner board
* Fri 01/17 - Inner-outer communication via shared memory
