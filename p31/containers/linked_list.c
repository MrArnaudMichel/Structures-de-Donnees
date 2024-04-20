//
// Created by arnaud on 28/11/2023.
//

#include "linked_list.h"

#include <stdio.h>

void ll_init(linked_list *ll, size_t value_size){
    ll->head = NULL;
    ll->value_size = value_size;
}
void ll_free(linked_list *ll){
    linked_list_node *n = ll->head;
    while(n != NULL){
        linked_list_node *next = n->next;
        free(n->data);
        free(n);
        n = next;
    }
    ll->head = NULL;
    ll->value_size = 0;
}

size_t ll_size(linked_list const *ll){
    size_t size = 0;
    linked_list_node *n = ll->head;
    while(n != NULL){
        size++;
        n = n->next;
    }
    return size;
}

size_t ll_value_size(linked_list const *ll){
    return ll->value_size;
}

linked_list_node const *ll_get_node(linked_list const *ll, size_t index){
    linked_list_node *n = ll->head;
    for(size_t i = 0; i < index; i++){
        n = n->next;
    }
    return n;
}


void ll_set_node_value(linked_list const *ll, linked_list_node *n, void const *value){
    memcpy(n->data, value, ll->value_size);
}


linked_list_node *ll_push_back(linked_list *ll, void const *value){
    linked_list_node *n = malloc(sizeof(linked_list_node));
    n->data = malloc(ll->value_size);
    memcpy(n->data, value, ll->value_size);
    n->next = NULL;
    if(ll->head == NULL){
        ll->head = n;
    }else{
        linked_list_node *last = ll->head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = n;
    }
    return n;
}
linked_list_node *ll_push_front(linked_list *ll, void const *value){
    linked_list_node *n = malloc(sizeof(linked_list_node));
    n->data = malloc(ll->value_size);
    memcpy(n->data, value, ll->value_size);
    n->next = ll->head;
    ll->head = n;
    return n;
}

linked_list_node *ll_insert_after_node(linked_list *ll, linked_list_node *n,
                                       void const *value){
    linked_list_node *new_node = malloc(sizeof(linked_list_node));
    new_node->data = malloc(ll->value_size);
    memcpy(new_node->data, value, ll->value_size);
    new_node->next = n->next;
    n->next = new_node;
    return new_node;
}

linked_list_node *ll_insert_before_node(linked_list *ll, linked_list_node *n,
                                        void const *value){
    linked_list_node *new_node = malloc(sizeof(linked_list_node));
    new_node->data = malloc(ll->value_size);
    memcpy(new_node->data, value, ll->value_size);
    new_node->next = n;
    if(n == ll->head){
        ll->head = new_node;
    }else{
        linked_list_node *prev = ll->head;
        while(prev->next != n){
            prev = prev->next;
        }
        prev->next = new_node;
    }
    return new_node;
}

void ll_erase_node(linked_list *ll, linked_list_node *n){
    if(n == ll->head){
        ll->head = n->next;
    }else{
        linked_list_node *prev = ll->head;
        while(prev->next != n){
            prev = prev->next;
        }
        prev->next = n->next;
    }
    free(n->data);
    free(n);
}

linked_list_node const *find(linked_list const *ll, void const *value, bool (*equals)(void const *a, void const *b)){
    linked_list_node *n = ll->head;
    while(n != NULL){
        if(equals(n->data, value)){
            return n;
        }
        n = n->next;
    }
    return NULL;
}

