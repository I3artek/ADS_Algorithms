/*
 * Player 1 (P1) has n cards and Player 2 (P2) has m cards
 * I assume they will play for k rounds, where k <= min(n, m)
 * P1 is very ambitious and has to win more than k/2 games
 * In other words, draws are counted as loses for P1
 * In the worst case scenario, k worst cards from P1
 * and k best cards from P2 will be picked
 * In the full algorithm, the best solution should be found so
 * that it works for k best cards from P2 and any k cards from P1
 * But I consider only the scenario where specific k cards are picked from both
 * (k can be set to be equal k = n = m, and then we will consider whole decks)
 * The code is already long and the implementation would be similar but longer
 *
 * To win, P1 has to win k/2 + 1 times (integer division)
 *
 * While increaseing the strength of the cards of P1
 * I take maximum strength of P2 + 1 as the max to which
 * we can increase (no impact if we increase further)
 *
 * Considering the algorithm, it works as follows
 *
 * 1. We check if current deck of P1 wins with P2
 * 2.a. If yes, we return the current cost and
 *      (if applicable) set current solution as best
 * 2.b. If no, then we check which cost is smaller:
 *      - if we increase the current card's strength
 *        (if possible)
 *      - if we go to the next card (if possible)
 * 3. In both cases, we invoke the function recursively
 *    with proper arguments and go to point 1.
 *
 * The algorithm itself is recursive, but we do not need
 * Master's Theorem in this case as its purpose is to invoke
 * function check_all_matchups with proper arguments
 * If the algorithm cheks all the possibilities, this means
 * that function check_all_matchups will be invoked at most
 * x^k times (input dependent) where x is the maximum strength
 * of any card of Player 2 and k is the size of deck used to play
 * The function itself checks all possible permutations of cards
 * of Player 1 against constant permutation of cards of Player 2
 * This number is equal to k! and that's how many times
 * the function check_matchup (linear time complexity) will be invoked
 * Therefore, the time complexity of the whole algorithm is:
 *
 * T(n)= O(x^k * k! * k)
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define GO_NEXT 1
#define INCREASE 2
#define DO_NOTHING 0

typedef struct{
    int *cards;
    int size;
}deck_t;

typedef struct{
    int *cards;
    int size;
    int cost;
}solution_t;

deck_t *create_deck(int *cards, int n);

void delete_deck(deck_t *deck);

void QuickSort(int A[], int size);

void swap(int *a, int *b);

void sort_deck(deck_t deck);

void permute(int *arr, int l, int r, deck_t A, deck_t B, int *out_result);

void check_all_matchups(deck_t A, deck_t B, int *out_result);

int check_matchup(deck_t A, deck_t B);

int silent_check_matchup(deck_t A, deck_t B);

int min(int a, int b);

int decide(deck_t A, deck_t B, int cost, int current, int decision, solution_t *best_solution);

int *copy_array(int *arr, int n);

int main() {

    int n = 5;
    int m = 5;
    int P1_cards[] = {1, 2, 3, 4, 5};
    int P2_cards[] = {1, 3, 5, 4, 2};

    int k = 4;

    deck_t *P1 = create_deck(P1_cards, n);
    deck_t *P2 = create_deck(P2_cards, m);

    sort_deck(*P1);
    sort_deck(*P2);

    //we take the lowest cards from P1
    deck_t *P1_k_cards = create_deck(P1->cards, k);
    //and highest from P2
    deck_t *P2_k_cards = create_deck(P2->cards + P2->size - k, k);

    solution_t best;
    best.size = k;
    best.cards = NULL;
    //this is the highest possible cost,
    //so we use it to avoid checking
    //if any solution was found yet
    best.cost = k * P1_k_cards->cards[k - 1] + 1;


    int cost = decide(*P1_k_cards, *P2_k_cards, 0, 0, DO_NOTHING, &best);

    printf("-----------------------------------------------------\n");
    printf("To guarantee a win, Player 1 has to spend %d dollars\n", best.cost);
    printf("And upgrade his cards from:\n");
    for(int i = 0; i < P1_k_cards->size; i++)
    {
        printf("%d ", P1_k_cards->cards[i]);
    }
    printf("\nTo:\n");
    for(int i = 0; i < best.size; i++)
    {
        printf("%d ", best.cards[i]);
    }
    printf("\n");


    delete_deck(P1);
    delete_deck(P2);

    delete_deck(P1_k_cards);
    delete_deck(P2_k_cards);

    return 0;
}

int decide(deck_t A, deck_t B, int cost, int current, int decision, solution_t *best_solution)
{
    int *initial_cards = A.cards;
    A.cards = copy_array(initial_cards, A.size);

    if(decision == INCREASE)
    {
        A.cards[current]++;
        cost++;
    }
    else if(decision == GO_NEXT)
    {
        current++;
    }

    int P1_wins = 1;
    check_all_matchups(A, B, &P1_wins);
    if(P1_wins)
    {
        printf("\nPlayer 1 wins after spending %d dollars with cards:\n", cost);
        for(int i = 0; i < A.size; i++)
        {
            printf("%d ", A.cards[i]);
        }
        printf("\n\n");

        if(cost < best_solution->cost)
        {
            best_solution->cost = cost;
            free(best_solution->cards);
            best_solution->cards = A.cards;
            A.cards = initial_cards;
        }
        else
        {
            free(A.cards);
            A.cards = initial_cards;
        }

        return cost;
    }
    //B.cards[B.size - 1] is the maximum element in B
    if(current == A.size - 1 && A.cards[current] > B.cards[B.size - 1])
    {
        //we cannot move to the next card and cannot increase

        free(A.cards);
        A.cards = initial_cards;

        return -1;
    }
    if(current == A.size - 1)
    {
        //we cannot move to the next card

        int ret = decide(A, B, cost, current, INCREASE, best_solution);

        if(ret != -1 && ret < best_solution->cost)
        {
            best_solution->cost = ret;
            free(best_solution->cards);
            best_solution->cards = A.cards;
            A.cards = initial_cards;
        }
        else
        {
            free(A.cards);
            A.cards = initial_cards;
        }

        return ret;
    }
    if(A.cards[current] > B.cards[B.size - 1])
    {
        //we cannot increase more

        int ret = decide(A, B, cost, current, GO_NEXT, best_solution);

        if(ret != -1 && ret < best_solution->cost)
        {
            best_solution->cost = ret;
            free(best_solution->cards);
            best_solution->cards = A.cards;
            A.cards = initial_cards;
        }
        else
        {
            free(A.cards);
            A.cards = initial_cards;
        }

        return ret;
    }
    int go_next_cost = decide(A, B, cost, current, GO_NEXT, best_solution);
    int increase_cost = decide(A, B, cost, current, INCREASE, best_solution);

    int final_cost;

    if(go_next_cost == -1)
    {
        final_cost = increase_cost;
    }
    else if(increase_cost == -1)
    {
        final_cost = go_next_cost;
    }
    else
    {
        final_cost = min(go_next_cost, increase_cost);
    }

    if(final_cost != -1 && final_cost < best_solution->cost)
    {
        best_solution->cost = final_cost;
        free(best_solution->cards);
        best_solution->cards = A.cards;
        A.cards = initial_cards;
    }
    else
    {
        free(A.cards);
        A.cards = initial_cards;
    }

    return final_cost;
}

//I assume A.size == B.size
int check_matchup(deck_t A, deck_t B)
{
    int points = 0;

    printf("The matchup:\n");

    printf("P1 ? P2\n");
    for(int i = 0; i < A.size; i++)
    {
        printf(" %d ", A.cards[i]);
        if(A.cards[i] > B.cards[i])
        {
            points++;
            printf("> ");
        }
        else if(A.cards[i] < B.cards[i])
        {
            printf("< ");
        }
        else
        {
            printf("= ");
        }
        printf("%d \n", B.cards[i]);
    }

    printf("Player 1 has %d out of %d points\n\n", points, A.size);

    return points > A.size / 2;
}

//the same as above, but without printfs
//O(k)
int silent_check_matchup(deck_t A, deck_t B)
{
    int points = 0;
    for(int i = 0; i < A.size; i++)
    {
        if(A.cards[i] > B.cards[i])
        {
            points++;
        }
    }
    return points > A.size / 2;
}

void permute(int *arr, int l, int r, deck_t A, deck_t B, int *out_result)
{
    if(l == r)
    {
        int p1_won_all = silent_check_matchup(A, B);
        if(*out_result == 1)
        {
            *out_result = p1_won_all;
        }
    }
    else
    {
        for(int i = l; i <= r; i++)
        {
            swap(arr + l, arr + i);
            permute(arr, l + 1, r, A, B, out_result);
            swap(arr + l, arr + i);
        }
    }
}

void check_all_matchups(deck_t A, deck_t B, int *out_result)
{

    printf("Checking possible permutations for:\n");
    printf("Player 1: ");
    for(int i = 0; i < A.size; i++)
    {
        printf("%d ", A.cards[i]);
    }
    printf("\n");
    printf("Player 2: ");
    for(int i = 0; i < B.size; i++)
    {
        printf("%d ", B.cards[i]);
    }
    printf("\n");
    permute(A.cards, 0, A.size - 1, A, B, out_result);
}

deck_t *create_deck(int *cards, int n)
{
    deck_t *deck = calloc(1, sizeof(deck_t));
    deck->size = n;
    deck->cards = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        deck->cards[i] = cards[i];
    }
    return deck;
}

void delete_deck(deck_t *deck)
{
    free(deck->cards);
    free(deck);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//sorts in ascending order
void QuickSort(int A[], int size)
{
    if(size <= 1)
    {
        return;
    }
    int *pivot = A + size - 1;
    int *l = A;
    int *r = A + size - 2;
    while(r + 1 != l)
    {
        if(*r <= *pivot && *l > *pivot)
        {
            swap(r, l);
            l++;
            r--;
        }
        if(*r > *pivot)
        {
            r--;
        }
        if(*l <= *pivot)
        {
            l++;
        }
    }
    if(pivot != l)
    {
        swap(pivot, l);
    }
    QuickSort(A, r - A + 1);
    QuickSort(l + 1, size + A - r - 2);
}

void sort_deck(deck_t deck)
{
    QuickSort(deck.cards, deck.size);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int *copy_array(int *arr, int n)
{
    int *tmp = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        tmp[i] = arr[i];
    }
    return tmp;
}
