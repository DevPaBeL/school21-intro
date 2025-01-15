#include "./list.h"

struct node* init(struct door* door) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->door = door;
        newNode->next = NULL;
    }
    return newNode;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* tmp = malloc(sizeof(struct node));
    if (tmp != NULL) {
        tmp->door = door;
        tmp->next = elem->next;
        elem->next = tmp;
    }
    return tmp;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current_node = root;
    while (current_node->next != NULL && current_node->door->id != door_id) {
        current_node = current_node->next;
    }
    return current_node;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* current_node = root;
    struct node* prev_node = NULL;
    struct node* tmp = NULL;
    while (current_node != elem) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (prev_node) {
        tmp = prev_node->next;
        prev_node->next = current_node->next;
    } else {
        tmp = current_node->next;
        root->next = current_node->next;
    }
    free(elem->door);
    free(elem);
    return tmp;
}

void destroy(struct node* root) {
    if (root == NULL) return;
    while (root != NULL) {
        struct node* tmp = root;
        root = root->next;
        if (tmp->door != NULL) {
            free(tmp->door);
        }
        free(tmp);
    }
}