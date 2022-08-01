/** Author: Henrique Reis Neves
 * SID: 100313047
 * 
 * Lab11: Problem Solving
 * Lab11.cpp file
 * Last Update: 2022-07-31
**/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// a point_t will represent a 2D coordinate point in the chess grid
// point_t.first = x coordinate
// point_t.second = y coordinate
typedef pair<int, int> point_t;
const int BOARD_DIMENTION = 8;


// Checks if a point is inside the boundaries of the grid
bool isValid(point_t point) {
    return !(point.first < 0 || point.second < 0 || point.first > 7 || point.second > 7);
}

// Function returns a vector of points which is the path from start to end
vector<point_t> knight_moves(point_t start, point_t destination) {
    point_t previous[BOARD_DIMENTION][BOARD_DIMENTION];
    bool visited[BOARD_DIMENTION][BOARD_DIMENTION]; 
    vector<point_t> path; 
    point_t invalidPoint = {-1, -1};
    queue<point_t> queue;

    struct PossibleMove {
    int dx;
    int dy;
    };

    PossibleMove possibleMoves[] = {
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2}
    };

    // Set the grid to -1 and set all points to unvisited
    for(int i = 0; i < BOARD_DIMENTION; ++i) {
        for(int j = 0; j < BOARD_DIMENTION; ++j) {
            previous[i][j] = {-1, -1};
            visited[i][j] = false;
        }
    }

    // Starting queue
    queue.push(start); 

    while(!queue.empty()) {
        point_t current = queue.front();
        visited[current.first][current.second] = true; 
        queue.pop();

        // check for possible moves
        for(int i = 0; i < BOARD_DIMENTION; i++) {
            point_t next = {current.first + possibleMoves[i].dx, current.second + possibleMoves[i].dy};
            if(isValid(next) && !visited[next.first][next.second]) {
                queue.push(next);
                previous[next.first][next.second] = current;
            }
        }
    }

    point_t current = destination; 
    
    while(current != start) {
        if(current == invalidPoint) {
            break;
        }
        path.push_back(current);
        current = previous[current.first][current.second];
    }
    path.push_back(start);

    // Reversing path to the properly order
    reverse(path.begin(), path.end());
    return path;
}

void printPath(vector<point_t> path, point_t start, point_t end) {
    cout << "You made it in " << path.size() - 1 << " moves from [" <<
        start.first << ", " << start.second << "] to [" <<
        end.first << ", " << end.second << "]! Here is your path: "
    << endl;
    for(point_t p: path) {
        cout << "[" << p.first << ", " << p.second << "]" << endl;
    }
}

int main() {

    point_t start, end;

    // get starting point and the destination from user and check if both are valid
    cout << "Enter the starting point: ";
    cin >> start.first >> start.second;
    cout << "Enter the destination location: ";
    cin >> end.first >> end.second;
    while(!isValid(start) || !isValid(end)) {
        cout << "Invalid starting or ending point! Try again." << endl;
        cout << "Enter the starting point: ";
        cin >> start.first >> start.second;
        cout << "Enter the destination location: ";
        cin >> end.first >> end.second;
    }

    // assign the path to a vector of points
    
    vector<point_t> path = knight_moves(start, end);
    
    printPath(path, start, end);
    return 0;
}
