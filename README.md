# Josephus-Problem
Fun Game/Problem made using Queue in C++
<br>This C++ code implements the Josephus problem, a classic mathematical game of elimination.
<br>
<br>The code defines a template class `Queue` which implements a linked list-based queue data structure. It provides methods for enqueueing, dequeueing, checking if the queue is empty, and printing its contents.
<br>
<br>The `josephusProblem` function simulates the Josephus problem:
<br>- It takes the value of `k` (the count of persons to be skipped before elimination), the total number of players (`n`), and a reference to a `Queue` instance.
<br>- The function simulates the elimination process, repeatedly dequeuing and enqueueing players until only one player remains.
<br>- It prints the progress of the game, including the starting player, the value of `k`, and the eliminated players.
<br>
<br>The `Start` function:
<br>- Initializes a `Queue` of player names based on user input.
<br>- Takes user input for the value of `k`.
<br>- Calls the `josephusProblem` function to simulate the game using the provided values.
<br>
<br>The `main` function:
<br>- Calls the `Start` function to begin the Josephus game.
<br>
In summary, thecode demonstrates the implementation of the Josephus problem using a queue data structure. Players are eliminated in a cyclic manner until only one player remains, and the progress of the game is displayed through console output.
