// Danish Faruqi

#include <iostream>
#include <stdlib.h> // abs function
#include "maze.h"

using std::ostream;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;
using std::cout;

void triangle(/*ostream& outs,*/ unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/

//void triangle (int m, int n)
//{
//    if ( n == 0) // so it doesn't loop forever when there is
//    {
//        return;
//    }
//    if( m > n) // m can't be bigger than n so don't print anything
//    {
//        return;
//    }
//    if(m == n+1)
//    {
//        return;
//    } // n conroll == 0
//    std::cout << std::string(m, '*') << std::endl;
//    triangle(m+1, n);
//    std::cout << std::string(m, '*') << std::endl;
{
    if ( n == 0) // so it doesn't loop forever when there is
    {
        return;
    }
    if( m > n) // m can't be bigger than n so don't print anything
    {
        return;
    }
    if(m == n+1) // gets the double line at the highest point of the triangle
    {
        return;
    } // n conroll == 0
    std::cout << std::string(m, '*') << std::endl;
    triangle(/*out,*/m+1, n);
    std::cout << std::string(m, '*') << std::endl;
    // cout is commented out, couldn't find the error but it was leaving space in my triangle,
    // something wrong with my syntax
}


//-------------------------------------------------------------------------------------------------------------------

//int count_ways_to_step(int number_of_stepping_stones)
//{ int n =0;
//
//    if(number_of_stepping_stones <=0)
//    {return 0;
//    }
//    // of go 2 steps and have forward
//    if(number_of_stepping_stones-2 == 0)
//    {
//        ++n;
//    }else{
//        count_ways_to_step(number_of_stepping_stones-2)
//        // + count_ways_to_step(number_of_stepping_stones );
//    }
//
//    // if 1 step and have foward
//    if(number_of_stepping_stones-1 == 0)
//    {
//        ++n;
//    }else{
//        count_ways_to_step(number_of_stepping_stones-1)
//        // + count_ways_to_step(number_of_stepping_stones );
//    }
//
//
//    // return if only 1 step
//
//    if(number_of_stepping_stones <= 1 )// base case
//    {
//        ++n;
//    }
//    return n;
//}

int count_ways_to_step(int number_of_stepping_stones)
// Precondition: number_of_stepping_stones > 0
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.
{

    // one stepping stone left, or only one there
    // counter that returns the number of steps, starts at 0

    // its basically fibonacci sequence, but gives you all the permutations /ways to get to the middle
    if (number_of_stepping_stones <= 1)
    {
        return 1;
    }
    return count_ways_to_step(number_of_stepping_stones - 2) + count_ways_to_step(number_of_stepping_stones -1);


}
//-------------------------------------------------------------------------------------------------------------------


bool print_path_through_maze(const maze_node* maze_position)
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.

{
    // check is pointer is null, nothing ahead of it, or id the finish


    //base case 1 - there is no node
//    if(maze_position == nullptr)
//    {
//        return false;
//    }


    // base case 2 - finish
    if(maze_position->is_finish())
    {
        return true;
    }

    // base case 3 - dead end, both pointers have to be
    if(maze_position->right() == nullptr && maze_position->left() == nullptr)
    {
        return false;
    }

    // checking and moving through the nodes, by returning true you allow it to
    // step back and go back to the other recursive sequence, but only if true
    if(print_path_through_maze(maze_position->left()))
    {
        cout<<"0";
        return true;
    }
    else if(print_path_through_maze(maze_position->right()))
    {
        cout<<"1";
        return true;
    }
}

int main()
{
//    std::cout<< count_ways_to_step(5);
    // You can test your code by adding it here.
   //triangle(4, 10);
//   maze m1(0);
//   cout<<print_path_through_maze(m1.get_start());

}
