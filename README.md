# Knight_moves
## Shows the simplest possible way (path) a Knight have to do from one position to another


A knight in chess can move to any square on the standard 8x8 chess board from any other square 
on the board, given enough turns (don’t believe it? See this: https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Knight%27s_tour_anim_2.gif/250px-Knight%27s_tour_anim_2.gif).

Its basic move is two steps forward and one step to the side. It can face any direction.
All the possible places you can end up after one move look like this:

![image](https://user-images.githubusercontent.com/39978017/182234274-62460ba2-dca6-4faf-a4dd-a855d7bc1514.png)

The function knight_moves shows the simplest possible way (path) to 
get from one square to another by outputting all squares the knight will stop on along the way.
By “simplest way”, I mean the path with the least move. 
The board can be represented in a 2-dimensional coordinates. The function would therefore 
look like:
• knight_moves([0,0],[1,2]) == [[0,0],[1,2]]
• knight_moves([0,0],[3,3]) == [[0,0],[1,2],[3,3]]
• knight_moves([3,3],[0,0]) == [[3,3],[1,2],[0,0]]

The main function asks for the dimension of two valid squares in the chess board (8x8) and then 
prints the total number of moves with the details.
