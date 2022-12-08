#ifndef LAB2_QUEUE_SNAKEALGORITHM_H
#define LAB2_QUEUE_SNAKEALGORITHM_H

class SnakeAlgorithm {
    int ladders[101] = {0};
    int snakes[101] = {0};
    int start = 0;//We start not on the board
    int end = 100;
    int steps[101] = {0};

    int count_steps(int sq)
    {
        if(sq == end)//by this if we allow 0 in the last field
        {
            steps[sq] = 0;
            return 0;
        }
        if(steps[sq] != 0)
        {
            return steps[sq];
        }
        int min_steps;
        if(ladders[sq] != 0)
        {
            min_steps = count_steps(ladders[sq]) - 1;//ladders and snakes do not count as steps
        }
        else if(snakes[sq] != 0)
        {
                int new_sq = snakes[sq];
                snakes[sq] = 0;
                steps[sq] = 9999;
                min_steps = count_steps(new_sq) - 1;//ladders and snakes do not count as steps
        }
        else
        {
            min_steps = count_steps(sq + 1);
            int max_dice_throw = end - sq < 6 ? end - sq : 6;
            for(int i = 2; i <= max_dice_throw; i++)
            {
                int temp_steps = count_steps(sq + i);
                min_steps = temp_steps < min_steps ? temp_steps : min_steps;
            }
        }
        min_steps++;
        steps[sq] = min_steps;
        return min_steps;
    }
public:

    void set_ladder(int from, int to)//squares are 1-100
    {
        ladders[from] = to;
    }
    void set_snake(int from, int to)//squares are 1-100
    {
        snakes[from] = to;
    }

    int smallest_number_of_steps()
    {
        count_steps(start);
        return steps[start];
    }
};


#endif //LAB2_QUEUE_SNAKEALGORITHM_H
