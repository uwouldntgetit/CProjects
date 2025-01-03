#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

/* I think that the best data structure for the snake is a queue where every element is a coordinate representing a part f the body.
 * The boyd part n is going to the place of the bodypart n+1
 * The head can go left, right or straight
 * if the head touches the body or the border then the game finishes
 * */

struct element {
    struct element *next;
    int x;
    int y;
}

// I make a function that given the length of the side of the map and some more parameters it returns if the game is finished
// Done
int check_finish(struct element queue, int size){
    struct element head = get_head(queue);

    while(queue.next){
        if(queue.x == head.x && queue.y == head.y)
            return 0;

        queue = *(queue.next);
    }
    
    if(head.x >= size || head.y >= size || head.x < 0 || head.y < 0)
        return 0;
    return 1;
}

// function that moves the snake


// Done
struct element * get_head(struct element queue){
    while(*(queue.next) != NULL){
        queue = *(queue.next);
    }
    return queue;
}
