#include "list.h"

#include <stdio.h>
void add(struct node* ll_doors, int id, int status);
void remove_by_id(struct node* ll, int id);
int test_add();
int test_remove();

int main() {
    if (!test_add())
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\n");
    if (!test_remove())
        printf("SUCCESS");
    else
        printf("FAIL");
    return 0;
}

void add(struct node* ll_doors, int id, int status) {
    struct door* door_to_add = malloc(sizeof(struct door));
    door_to_add->id = id;
    door_to_add->status = status;
    add_door(ll_doors, door_to_add);
}

void remove_by_id(struct node* ll, int id) {
    struct node* node_to_delete = find_door(id, ll);
    remove_door(node_to_delete, ll);
}

int test_add() {
    struct door* initdoor = malloc(sizeof(struct door));
    initdoor->id = 0;
    initdoor->status = 0;
    int error = 0;
    struct node* root = init(initdoor);
    add(root, 1, 1);
    add(root->next, 2, 1);
    add(root->next->next, 3, 0);
    int results[][2] = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 0},
    };
    int count = sizeof(results) / (sizeof(int) * 2);
    struct node* tmp = root;
    for (int i = 0; i < count && !error; i++) {
        if (tmp->door->id != results[i][0] || tmp->door->status != results[i][1]) {
            error = 1;
        }
        tmp = tmp->next;
        if (tmp == NULL && i != count - 1) {
            error = 1;
        }
    }
    destroy(root);
    return error;
}

int test_remove() {
    struct door* initdoor = malloc(sizeof(struct door));
    initdoor->id = 0;
    initdoor->status = 0;
    int error = 0;
    struct node* root = init(initdoor);
    // Append the doors
    add(root, 1, 1);
    add(root->next, 2, 1);
    add(root->next->next, 3, 0);
    remove_by_id(root, 2);
    int results[][2] = {
        {0, 0},
        {1, 1},
        {3, 0},
    };
    int count = sizeof(results) / (sizeof(int) * 2);
    struct node* tmp = root;
    for (int i = 0; i < count && !error; i++) {
        if (tmp->door->id != results[i][0] || tmp->door->status != results[i][1]) {
            error = 1;
        }
        tmp = tmp->next;
        if (tmp == NULL && i != count - 1) {
            error = 1;
        }
    }
    destroy(root);
    return error;
}
