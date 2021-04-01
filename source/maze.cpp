#include<main.h>
#include <ctime>

using namespace std;

pair<int, int> create_walls(vector<pair<int, int>> &walls){
    srand((unsigned) time(0));
    int num_mazes = 2;
    int result = (rand() % num_mazes) + 1;
    switch(result){
        case 1:
            walls.push_back(make_pair(0, 0));
            walls.push_back(make_pair(0, 1));
            walls.push_back(make_pair(1, 1));
            walls.push_back(make_pair(2, 1));
            walls.push_back(make_pair(2, 0));
            walls.push_back(make_pair(3, 0));
            walls.push_back(make_pair(4, 0));
            walls.push_back(make_pair(4, 1));
            walls.push_back(make_pair(4, 2));
            walls.push_back(make_pair(4, 3));
            walls.push_back(make_pair(3, 3));
            walls.push_back(make_pair(2, 3));
            walls.push_back(make_pair(2, 4));
            walls.push_back(make_pair(2, 5));
            walls.push_back(make_pair(3, 5));
            walls.push_back(make_pair(4, 5));
            walls.push_back(make_pair(5, 5));
            walls.push_back(make_pair(3, 6));
            walls.push_back(make_pair(3, 7));
            walls.push_back(make_pair(4, 7));
            walls.push_back(make_pair(5, 7));
            return make_pair(6, 8);
        case 2:
            walls.push_back(make_pair(0, 0));
            walls.push_back(make_pair(0, 5));
            walls.push_back(make_pair(0, 6));
            walls.push_back(make_pair(0, 7));
            walls.push_back(make_pair(1, 0));
            walls.push_back(make_pair(1, 1));
            walls.push_back(make_pair(1, 2));
            walls.push_back(make_pair(1, 3));
            walls.push_back(make_pair(1, 7));
            walls.push_back(make_pair(2, 3));
            walls.push_back(make_pair(2, 5));
            walls.push_back(make_pair(2, 7));
            walls.push_back(make_pair(3, 2));
            walls.push_back(make_pair(3, 3));
            walls.push_back(make_pair(3, 5));
            walls.push_back(make_pair(3, 7));
            walls.push_back(make_pair(4, 0));
            walls.push_back(make_pair(4, 1));
            walls.push_back(make_pair(4, 2));
            walls.push_back(make_pair(4, 5));
            walls.push_back(make_pair(4, 6));
            walls.push_back(make_pair(4, 7));
            walls.push_back(make_pair(5, 0));
            walls.push_back(make_pair(5, 4));
            walls.push_back(make_pair(5, 5));
            walls.push_back(make_pair(5, 7));
            walls.push_back(make_pair(6, 0));
            walls.push_back(make_pair(6, 7));
            walls.push_back(make_pair(6, 8));
            walls.push_back(make_pair(7, 0));
            walls.push_back(make_pair(7, 2));
            walls.push_back(make_pair(7, 3));
            walls.push_back(make_pair(7, 4));
            walls.push_back(make_pair(7, 8));
            walls.push_back(make_pair(8, 0));
            walls.push_back(make_pair(8, 2));
            walls.push_back(make_pair(8, 4));
            walls.push_back(make_pair(8, 7));
            walls.push_back(make_pair(8, 8));
            walls.push_back(make_pair(9, 0));
            walls.push_back(make_pair(9, 1));
            walls.push_back(make_pair(9, 2));
            walls.push_back(make_pair(9, 4));
            walls.push_back(make_pair(9, 6));
            walls.push_back(make_pair(9, 7));
            walls.push_back(make_pair(10, 0));
            walls.push_back(make_pair(10, 4));
            walls.push_back(make_pair(10, 5));
            walls.push_back(make_pair(10, 6));
            walls.push_back(make_pair(11, 0));
            walls.push_back(make_pair(11, 4));
            walls.push_back(make_pair(11, 6));
            walls.push_back(make_pair(11, 7));
            walls.push_back(make_pair(11, 8));
            walls.push_back(make_pair(12, 8));
            return make_pair(13, 9);
    }
    return make_pair(-1, -1);
}