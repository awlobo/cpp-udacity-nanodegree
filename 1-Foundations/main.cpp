#include <algorithm> // for sort
#include <fstream>
#include <iostream>
#include <locale.h>
#include <sstream>
#include <string>
#include <vector>
using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myFile(path);
    vector<vector<State>> board{};
    if (myFile)
    {
        string line;
        while (getline(myFile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

/**
 * Compare the F values of two cells.
 */
bool Compare(vector<int> a, vector<int> b)
{
    int f1 = a[2] + a[3]; // f1 = g1 + h1
    int f2 = b[2] + b[3]; // f2 = g2 + h2
    return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), Compare);
}

// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool CheckValidCell(int x, int y, vector<vector<State>> &board)
{
    bool on_grid_x = (x >= 0 && x < board.size());
    bool on_grid_y = (y >= 0 && y < board[0].size());
    if (on_grid_x && on_grid_y)
        return board[x][y] == State::kEmpty;
    return false;
}

/**
 * Add a node to the open list and mark it as open. 
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
    // Add node to open vector, and mark grid cell as closed.
    openlist.push_back(vector<int>{x, y, g, h});
    grid[x][y] = State::kClosed;
}

/**
 * Expand current nodes's neighbors and add them to the open list.
 */
void ExpandNeighbors(vector<int> &currentNode, int goal[2], vector<vector<int>> &open, vector<vector<State>> &board)
{
    int x = currentNode[0];
    int y = currentNode[1];
    int g = currentNode[2];
    int h = currentNode[3];

    // Loop through current node's potential neighbors.
    for (int i = 0; i < 4; i++)
    {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        if (CheckValidCell(x2, y2, board))
        {
            // Increment g value and add neighbor to open list.
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, open, board);
        }
    }
}

/**
 * Implementation of A* search algorithm
 */
std::vector<vector<State>> Search(vector<vector<State>> &board, int init[2], int goal[2])
{
    // Create the vector of open nodes.
    vector<vector<int>> open{};

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);
    AddToOpen(x, y, g, h, open, board);

    while (!open.empty())
    {
        CellSort(&open);
        vector<int> node = open.back();
        open.pop_back();
        x = node[0];
        y = node[1];
        board[x][y] = State::kPath;

        // Check if we're done.
        if (x == goal[0] && y == goal[1])
        {
            board[init[0]][init[1]] = State::kStart;
            board[goal[0]][goal[1]] = State::kFinish;
            return board;
        }
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(node, goal, open, board);
    }

    // We've run out of new nodes to explore and haven't found a path.
    cout << "No path found!" << std::endl;
    return vector<vector<State>>{};
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
    case State::kPath:
        return "🚗   ";
    case State::kStart:
        return "🚦   ";
    case State::kFinish:
        return "🏁   ";
    default:
        return "⬛   ";
    }
}

void PrintBoard(const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

#include "test.cpp" // For testing solution

int main()
{
    setlocale(LC_ALL, "en_US.utf8");

    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFile("1.board");
    auto solution = Search(board, init, goal);
    PrintBoard(solution);
    // Tests
    TestHeuristic();
    TestAddToOpen();
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    TestExpandNeighbors();
}
