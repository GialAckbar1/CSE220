#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct int_obj{ 
    int val; 
    struct int_obj *next; 
}; 

struct list_int{ 
    int length; 
    struct int_obj *head; 
    struct int_obj *tail; 
    struct list_int *next; 
};

struct list_of_list_int{ 
    int length; 
    struct list_int *head; 
    struct list_int *tail; 
};

struct char220{ 
    char character; 
    struct char220 *next; 
}; 
 
struct string { 
    int length; 
    struct char220 *head; 
    struct char220 *tail; 
    struct string *next; 
};

struct list_string{ 
    int length; 
    struct string *head; 
    struct string *tail; 
    struct list_string *next; 
};

void add_int(int i, struct list_int *list) {
    struct int_obj *o = malloc(sizeof(struct int_obj));
    o->val = i;
    o->next = NULL;
    list->length++;

    if(list->head == NULL) {
        list->head = list->tail = o;
    } else {
        list->tail->next = o;
        list->tail = o;
    }
}

void add_char(char i, struct string *list) {
    struct char220 *o = malloc(sizeof(struct char220));
    o->character = i;
    o->next = NULL;
    list->length++;

    if(list->head == NULL) {
        list->head = list->tail = o;
    } else {
        list->tail->next = o;
        list->tail = o;
    }
}

void add_string(struct string *string, struct list_string *list) {
    struct string *o = malloc(sizeof(struct string));
    init_string(o);

    struct char220 *c = string->head;
    while (c != NULL) {
        add_char(c->character, o);
        c = c->next;
    }

    o->next = NULL;
    list->length++;

    if(list->head == NULL) {
        list->head = list->tail = o;
    } else {
        list->tail->next = o;
        list->tail = o;
    }
}

void add_list_int(struct list_int *list_int, struct list_of_list_int *list) {
    struct list_int *o = malloc(sizeof(struct list_int));
    init_list_int(o);

    struct int_obj *c = list_int->head;
    while (c != NULL) {
        add_int(c->val, o);
        c = c->next;
    }

    o->next = NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = list->tail = o;
    } else {
        list->tail->next = o;
        list->tail = o;
    }
}

void print_int_list(struct list_int *list) {
    struct int_obj *p = list->head;
    while(p != NULL) {
        if(p == list->tail) {
            printf("%d", p->val);
        } else {
            printf("%d\n", p->val);
        }
        p = p->next;
    }
}

void print_string(struct string *list) {
    struct char220 *p = list->head;
    while(p != NULL) {
        printf("%c", p->character);
        p = p->next;
    }
}

void init_list_int(struct list_int *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void init_string(struct string *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void init_list_string(struct list_string *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void init_list_of_list_int(struct list_of_list_int *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

struct string *string_convert(char* string) {
    struct string *list = malloc(sizeof(struct string));
    init_string(list);

    for (int i = 0; string[i] != '\0'; i++) {
        add_char(string[i], list);
    }

    return list;
}

void print_list_string(struct list_string *list) {
    struct string *string = list->head;
    int first = 1;
    while (string != NULL) {
        if (!first) {
            printf(", ");
        }
        print_string(string);
        string = string->next;
        first = 0;
    }
}