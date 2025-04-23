#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE* open_file() {
    char *filename = malloc(sizeof(char) * 100);
    printf("Enter file name:\n");
    scanf("%s", filename);
    FILE* file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("ERROR: NO FILE\n");
        return NULL;
    } else {
        return file_pointer;
    }
}
void remove_last_colon(struct string *s) {
    if (s == NULL || s->head == NULL || s->tail == NULL) {
        // Empty string, nothing to do
        return;
    }

    if (s->tail->character != ':') {
        // Last character is not ':', nothing to do
        return;
    }

    if (s->head == s->tail) {
        // Only one character, and it's ':'
        free(s->tail);
        s->head = NULL;
        s->tail = NULL;
        s->length = 0;
        return;
    }

    // More than one character
    struct char220 *current = s->head;
    while (current->next != s->tail) {
        current = current->next;
    }

    // Now current is the second-to-last node
    free(s->tail);
    s->tail = current;
    s->tail->next = NULL;
    s->length--; // important: decrease length
}
struct string *read_file(FILE* file_pointer) {
    char ch;
    struct string *str_obj = malloc(sizeof(struct string));
    init_string(str_obj);

    while ((ch = fgetc(file_pointer)) != EOF) {
        add_char(ch, str_obj);
    }

    return str_obj;
}

int check_strings_equal(struct string *str1, struct string *str2) {
    if (str1->length != str2->length) return 0;

    struct char220 *p1 = str1->head;
    struct char220 *p2 = str2->head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->character != p2->character) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

struct string *history_of_country(struct string *target_country, struct list_string *country_list, struct list_of_list_int *regime_list_collection) {
    struct string *curr_name = country_list->head;
    struct list_int *curr_history = regime_list_collection->head;

    while (curr_name != NULL && curr_history != NULL) {
        if (check_strings_equal(curr_name, target_country)) {
            int counts[4] = {0};
            struct int_obj *regime_node = curr_history->head;

            while (regime_node != NULL) {
                if (regime_node->val >= 0 && regime_node->val <= 3) {
                    counts[regime_node->val]++;
                }
                regime_node = regime_node->next;
            }

            int max_occurrence = -1;
            int dominant = -1;
            for (int i = 0; i < 4; i++) {
                if (counts[i] > max_occurrence) {
                    max_occurrence = counts[i];
                    dominant = i;
                }
            }

            struct string *result = malloc(sizeof(struct string));
            init_string(result);

            const char *regime_name;
            switch (dominant) {
                case 0: regime_name = "Closed autocracy"; break;
                case 1: regime_name = "Electoral autocracy"; break;
                case 2: regime_name = "Electoral democracy"; break;
                case 3: regime_name = "Liberal democracy"; break;
                default: regime_name = "Unknown"; break;
            }

            for (const char *p = regime_name; *p; p++) {
                add_char(*p, result);
            }

            return result;
        }
        curr_name = curr_name->next;
        curr_history = curr_history->next;
    }
    return NULL;
}

void set_country_names_and_list_of_regime_lists(struct string *file_data, struct list_string *countries, struct list_of_list_int *regime_lists) {
    struct char220 *ptr = file_data->head;

    while (ptr != NULL && ptr->character != '\n') ptr = ptr->next;
    if (ptr != NULL) ptr = ptr->next;

    struct string *last_name = NULL;
    struct list_int *current_list = NULL;

    while (ptr != NULL) {
        while (ptr != NULL && ptr->character != ',') ptr = ptr->next;
        if (ptr != NULL) ptr = ptr->next;

        struct string country_temp;
        init_string(&country_temp);
        while (ptr != NULL && ptr->character != ',') {
            add_char(ptr->character, &country_temp);
            ptr = ptr->next;
        }
        if (ptr != NULL) ptr = ptr->next;

        while (ptr != NULL && ptr->character != ',') ptr = ptr->next;
        if (ptr != NULL) ptr = ptr->next;

        while (ptr != NULL && ptr->character != ',') ptr = ptr->next;
        if (ptr != NULL) ptr = ptr->next;

        int regime_value = (ptr != NULL && ptr->character >= '0' && ptr->character <= '3') ? (ptr->character - '0') : -1;
        if (ptr != NULL) ptr = ptr->next;

        while (ptr != NULL && ptr->character != '\n') ptr = ptr->next;
        if (ptr != NULL) ptr = ptr->next;

        int new_country = 1;
        if (last_name != NULL && check_strings_equal(&country_temp, last_name)) {
            new_country = 0;
        }

        if (new_country) {
            if (current_list != NULL) {
                add_list_int(current_list, regime_lists);
                free(current_list);
            }

            struct string *new_name = malloc(sizeof(struct string));
            init_string(new_name);
            struct char220 *copy_ptr = country_temp.head;
            while (copy_ptr != NULL) {
                add_char(copy_ptr->character, new_name);
                copy_ptr = copy_ptr->next;
            }
            add_string(new_name, countries);
            last_name = new_name;

            current_list = malloc(sizeof(struct list_int));
            init_list_int(current_list);
        }

        if (regime_value >= 0) {
            add_int(regime_value, current_list);
        }
    }

    if (current_list != NULL) {
        add_list_int(current_list, regime_lists);
    }
}

struct list_string *sorted_historical_allies(struct string *target_regime, struct list_string *countries, struct list_of_list_int *regime_collections) {
    struct list_string *allied_countries = malloc(sizeof(struct list_string));
    init_list_string(allied_countries);

    struct string *curr_country = countries->head;
    struct list_int *curr_regime_list = regime_collections->head;

    while (curr_country != NULL && curr_regime_list != NULL) {
        struct string *dominant = history_of_country(curr_country, countries, regime_collections);

        if (dominant != NULL && check_strings_equal(dominant, target_regime)) {
            add_string(curr_country, allied_countries);
        }

        curr_country = curr_country->next;
        curr_regime_list = curr_regime_list->next;
    }

    if (allied_countries->length > 1) {
        int sorted_flag;
        do {
            sorted_flag = 0;
            struct string **ptr = &(allied_countries->head);

            while (*ptr != NULL && (*ptr)->next != NULL) {
                struct string *first = *ptr;
                struct string *second = first->next;

                struct char220 *c1 = first->head;
                struct char220 *c2 = second->head;
                int cmp_result = 0;

                while (c1 != NULL && c2 != NULL && c1->character == c2->character) {
                    c1 = c1->next;
                    c2 = c2->next;
                }

                if (c1 != NULL && c2 != NULL) {
                    cmp_result = c1->character - c2->character;
                } else if (c1 != NULL) {
                    cmp_result = 1;
                } else if (c2 != NULL) {
                    cmp_result = -1;
                }

                if (cmp_result > 0) {
                    first->next = second->next;
                    second->next = first;
                    *ptr = second;
                    sorted_flag = 1;
                }

                ptr = &(*ptr)->next;
            }
        } while (sorted_flag);
    }

    return allied_countries;
}

void sorted_coup_detat_count(int max_display, struct list_string *countries, struct list_of_list_int *regime_listings, struct list_string *out_country_list, struct list_int *out_coups) {
    struct string *country_it = countries->head;
    struct list_int *regime_it = regime_listings->head;

    while (country_it != NULL && regime_it != NULL) {
        int coups_count = 0;
        int previous_val = -1;

        struct int_obj *curr = regime_it->head;
        while (curr != NULL) {
            if (previous_val != -1 && curr->val != previous_val) {
                coups_count++;
            }
            previous_val = curr->val;
            curr = curr->next;
        }

        struct string *copy_country = malloc(sizeof(struct string));
        init_string(copy_country);
        struct char220 *char_ptr = country_it->head;
        while (char_ptr != NULL) {
            add_char(char_ptr->character, copy_country);
            char_ptr = char_ptr->next;
        }

        add_string(copy_country, out_country_list);
        add_int(coups_count, out_coups);

        country_it = country_it->next;
        regime_it = regime_it->next;
    }

    int changed;
    do {
        changed = 0;
        struct string *prev_country = NULL;
        struct string *curr_country = out_country_list->head;
        struct int_obj *prev_coup = NULL;
        struct int_obj *curr_coup = out_coups->head;

        while (curr_country != NULL && curr_country->next != NULL && curr_coup != NULL && curr_coup->next != NULL) {
            int swap_needed = 0;

            if (curr_coup->val < curr_coup->next->val) {
                swap_needed = 1;
            } else if (curr_coup->val == curr_coup->next->val) {
                struct char220 *ca = curr_country->head;
                struct char220 *cb = curr_country->next->head;

                while (ca != NULL && cb != NULL) {
                    if (ca->character > cb->character) {
                        swap_needed = 1;
                        break;
                    } else if (ca->character < cb->character) {
                        break;
                    }
                    ca = ca->next;
                    cb = cb->next;
                }

                if (ca != NULL && cb == NULL) {
                    swap_needed = 1;
                }
            }

            if (swap_needed) {
                struct string *temp_str = curr_country->next;
                curr_country->next = temp_str->next;
                temp_str->next = curr_country;
                if (prev_country) {
                    prev_country->next = temp_str;
                } else {
                    out_country_list->head = temp_str;
                }

                struct int_obj *temp_int = curr_coup->next;
                curr_coup->next = temp_int->next;
                temp_int->next = curr_coup;
                if (prev_coup) {
                    prev_coup->next = temp_int;
                } else {
                    out_coups->head = temp_int;
                }

                changed = 1;
            }

            prev_country = curr_country;
            prev_coup = curr_coup;
            curr_country = curr_country->next;
            curr_coup = curr_coup->next;
        }
    } while (changed);

    if (max_display < out_country_list->length) {
        struct string *curr_str = out_country_list->head;
        struct int_obj *curr_int = out_coups->head;

        for (int i = 1; i < max_display && curr_str != NULL; i++) {
            curr_str = curr_str->next;
            curr_int = curr_int->next;
        }

        if (curr_str != NULL) {
            curr_str->next = NULL;
            out_country_list->tail = curr_str;
            out_country_list->length = max_display;

            curr_int->next = NULL;
            out_coups->tail = curr_int;
            out_coups->length = max_display;
        }
    }
}
