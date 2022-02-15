// C++ Enumerations

#include <iostream>
using namespace std;

enum season {
    spring,
    summer,
    autumn,
    winter
};

typedef enum {
    north,
    west,
    south,
    east
} direction_t;

int main() {
    season x = winter;
    cout << x << endl;
    direction_t y = west;
    cout << y << endl;
    return 0;
}