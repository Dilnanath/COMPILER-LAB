#include <stdio.h>
#include <string.h>

int main() {
    int no_s, no_sym, no_f, fin[10], len;
    char sym[20][10], str[100];
    int f=0;
    
    printf("Enter number of states: ");
    scanf("%d", &no_s);

    printf("Enter number of symbols: ");
    scanf("%d", &no_sym);

    printf("Enter the symbols:\n");
    for (int i = 0; i < no_sym; i++) {
	printf("Symbol %d: ", i + 1);
	scanf("%s", sym[i]);
    }

    printf("Enter number of final states: ");
    scanf("%d", &no_f);

    printf("Enter final states:\n");
    for (int i = 0; i < no_f; i++) {
	scanf("%d", &fin[i]);
    }

    int transition[no_s][no_sym];
    printf("Enter the transition table:\n");
    for (int i = 0; i < no_s; i++) {
	for (int j = 0; j < no_sym; j++) {
	    printf("From state %d using symbol %s: ", i, sym[j]);
	    scanf("%d", &transition[i][j]);
	}
    }
    while(f!=1)
	    {
	    printf("Enter input string: ");
	    scanf("%s", str);
	    len = strlen(str);

	    int current_state = 0;
	    int accepted = 0;

	    for (int i = 0; i < len; i++) {
		char c[2] = {str[i], '\0'};
		int sym_index = -1;

		for (int j = 0; j < no_sym; j++) {
		    if (strcmp(c, sym[j]) == 0) {
		        sym_index = j;
		        break;
		    }
		}

		if (sym_index == -1) {
		    printf("Invalid symbol: %c\n", str[i]);
		    return 0;
		}

		current_state = transition[current_state][sym_index];
	    }

	    for (int i = 0; i < no_f; i++) {
		if (current_state == fin[i]) {
		    accepted = 1;
		    break;
		}
	    }

	    if (accepted)
		printf("The string is acceptable.\n");
	    else
		printf("The string is not acceptable.\n");

	    printf("If you want to exit enter 1: ");
	    scanf("%d",&f);
	    }
	}
