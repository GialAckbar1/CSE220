#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.h"
#include "func.h"

int main() {
    FILE* file_ptr = open_file();
    struct string *file_input = read_file(file_ptr);
    struct list_string *countries = malloc(sizeof(struct list_string));
    struct list_of_list_int *regime_lists = malloc(sizeof(struct list_of_list_int));

    init_list_string(countries);
    init_list_of_list_int(regime_lists);
    set_country_names_and_list_of_regime_lists(file_input, countries, regime_lists);
    fclose(file_ptr);

    char user_choice;

    while(1) {
        printf("\nRegime Options:\n\t(1) Display regime history\n\t(2) Display allies\n\t(3) Display chaotic regimes\n\n");
        printf("Input an option (Q to quit):\n");

        do {
            user_choice = getchar();
        } while (user_choice == '\n' || user_choice == ' ' || user_choice == '\t');

        while (getchar() != '\n');

        if(user_choice == 'Q' || user_choice == 'q') {
            printf("The end.");
            return 0;
        }

        if(user_choice == '1') {
            int valid_input = 0;
            while (!valid_input) {
                printf("\nEnter a country:\n");
                struct string user_country;
                init_string(&user_country);

                char ch;
                while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
                if (ch != EOF) add_char(ch, &user_country);

                while ((ch = getchar()) != '\n' && ch != EOF) {
                    add_char(ch, &user_country);
                }

                if (user_country.length == 0) {
                    printf("Invalid country. Please try again.\n");
                    continue;
                }

                struct string *scan = countries->head;
                int match_found = 0;

                while (scan != NULL) {
                    if (check_strings_equal(scan, &user_country)) {
                        match_found = 1;
                        break;
                    }
                    scan = scan->next;
                }

                if (match_found) {
                    struct string *dominant_regime = history_of_country(&user_country, countries, regime_lists);
                    printf("\nHistorically ");
                    print_string(&user_country);
                    printf(" has mostly been a");
                    char first_letter = dominant_regime->head->character;
                    if (first_letter == 'A' || first_letter == 'E' || first_letter == 'I' || first_letter == 'O' || first_letter == 'U') {
                        printf("n ");
                    } else {
                        printf(" ");
                    }
                    print_string(dominant_regime);
                    printf(".\n");
                    valid_input = 1;
                } else {
                    printf("Invalid country. Please try again.\n");
                }
            }
        }
        else if (user_choice == '2') {
            int regime_valid = 0;
            while (!regime_valid) {
                printf("\nEnter a regime:\n");
                struct string entered_regime;
                init_string(&entered_regime);

                char ch;
                while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
                if (ch != EOF) add_char(ch, &entered_regime);

                while ((ch = getchar()) != '\n' && ch != EOF) {
                    add_char(ch, &entered_regime);
                }

                struct string possible_regimes[4];
                const char *regime_labels[] = {
                    "Closed autocracy",
                    "Electoral autocracy",
                    "Electoral democracy",
                    "Liberal democracy"
                };

                for (int i = 0; i < 4; i++) {
                    init_string(&possible_regimes[i]);
                    for (const char *p = regime_labels[i]; *p; p++) {
                        add_char(*p, &possible_regimes[i]);
                    }
                }

                int valid_selection = 0;
                for (int i = 0; i < 4; i++) {
                    if (check_strings_equal(&entered_regime, &possible_regimes[i])) {
                        valid_selection = 1;
                        break;
                    }
                }

                if (!valid_selection) {
                    printf("Invalid regime. Please try again.\n");
                    continue;
                }

                struct list_string *ally_list = sorted_historical_allies(&entered_regime, countries, regime_lists);

                printf("\nHistorically these countries are allies of type: ");
                remove_last_colon(&entered_regime);
                print_string(&entered_regime);
                printf(":\n\n");

                if (ally_list->head == NULL) {
                    printf("No countries found with this regime.\n\n");
                } else {
                    print_list_string(ally_list);
                    printf(".\n");
                }

                regime_valid = 1;
            }
        }
        else if (user_choice == '3') {
            int amount;
            int amount_valid = 0;
            char number_input[100];

            while (!amount_valid) {
                printf("\nEnter how many to display:\n");
                int idx = 0;
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF && idx < 99) {
                    number_input[idx++] = ch;
                }
                number_input[idx] = '\0';

                amount_valid = 1;
                for (int j = 0; j < idx; j++) {
                    if (number_input[j] < '0' || number_input[j] > '9') {
                        amount_valid = 0;
                        break;
                    }
                }

                if (amount_valid && idx > 0) {
                    amount = 0;
                    for (int j = 0; j < idx; j++) {
                        amount = amount * 10 + (number_input[j] - '0');
                    }

                    if (amount > 0) {
                        amount_valid = 1;
                    } else {
                        amount_valid = 0;
                    }
                }

                if (!amount_valid) {
                    printf("Invalid number. Please try again.\n");
                }
            }

            struct list_string result_countries;
            struct list_int change_counts;
            init_list_string(&result_countries);
            init_list_int(&change_counts);

            sorted_coup_detat_count(amount, countries, regime_lists, &result_countries, &change_counts);

            printf("                  Country  Changes\n\n");

            struct string *curr_country = result_countries.head;
            struct int_obj *curr_change = change_counts.head;

            while (curr_country && curr_change) {
                int padding = 25 - curr_country->length;
                for (int i = 0; i < padding; i++) printf(" ");
                print_string(curr_country);

                printf("  %7d\n", curr_change->val);

                curr_country = curr_country->next;
                curr_change = curr_change->next;
            }
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
    }
}
