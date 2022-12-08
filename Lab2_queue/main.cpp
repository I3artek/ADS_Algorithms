#include "queue.h"
#include "SnakeAlgorithm.h"

int main() {

    SnakeAlgorithm s;
    s.set_ladder(1,38);
    s.set_ladder(4,14);
    s.set_ladder(9,31);
    s.set_ladder(21,42);
    s.set_ladder(28,84);
    s.set_ladder(51,67);
    s.set_ladder(72,91);
    s.set_ladder(80,99);

    s.set_snake(17, 7);
    s.set_snake(54, 34);
    s.set_snake(62, 19);
    s.set_snake(64, 60);
    s.set_snake(87, 36);
    s.set_snake(93, 73);
    s.set_snake(95, 75);
    s.set_snake(98, 79);
    cout << s.smallest_number_of_steps();

    return 0;
}