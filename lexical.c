#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *op,*fp2;

    // Check for correct usage
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    fp1 = fopen(argv[1], "r");       // Input file
    op = fopen(argv[2], "w");       // Output file

    if (fp1 == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }
    if (op == NULL) {
        printf("Error opening output file: out3.c\n");
        fclose(fp1);
        return 1;
    }

    char ch, ch1;
    char lexeme[50];
    char keywords[20][50] = {
        "for", "void", "main", "FILE", "fopen", "char", "int", "if", "else", "while",
        "do", "include", "<stdio.h>", "<ctype.h>", "<string.h>", ""
    };
    int line = 1;
    int sr = 1;
    int i, j;
    int flag;

    while ((ch = fgetc(fp1)) != EOF) {
        i = 0;

        if (ch == ' ' || ch == '\t') {
            continue;
        } else if (ch == '\n') {
            line++;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            fprintf(op, "\n%d %c Arithmetic_op %d", sr++, ch, line);
        } else if (ch == '{' || ch == '(' || ch == '[') {
            fprintf(op, "\n%d %c Open_brackets %d", sr++, ch, line);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            fprintf(op, "\n%d %c Close_brackets %d", sr++, ch, line);
        } else if (ch == ';') {
            fprintf(op, "\n%d %c Semicolon %d", sr++, ch, line);
        } else if (ch == '_') {
            fprintf(op, "\n%d %c Special_character %d", sr++, ch, line);
        } else if (ch == '=') {
            ch1 = fgetc(fp1);
            if (ch1 == '=') {
                fprintf(op, "\n%d %c%c Relational_op %d", sr++, ch, ch1, line);
            } else {
                ungetc(ch1, fp1);
                fprintf(op, "\n%d %c Assignment_op %d", sr++, ch, line);
            }
        } else if (ch == '<' || ch == '>' || ch == '!') {
            ch1 = fgetc(fp1);
            if (ch1 == '=') {
                fprintf(op, "\n%d %c%c Relational_op %d", sr++, ch, ch1, line);
            } else {
                ungetc(ch1, fp1);
                fprintf(op, "\n%d %c Relational_op %d", sr++, ch, line);
            }
        } else if (isdigit(ch)) {
            lexeme[i++] = ch;
            flag = 0;
            while ((ch1 = fgetc(fp1)) != EOF && (isdigit(ch1) || ch1 == '.')) {
                if (ch1 == '.') flag = 1;
                lexeme[i++] = ch1;
            }
            lexeme[i] = '\0';
            ungetc(ch1, fp1);
            if (flag == 0)
                fprintf(op, "\n%d %s Number %d", sr++, lexeme, line);
            else
                fprintf(op, "\n%d %s Floating_Number %d", sr++, lexeme, line);
        } else if (isalpha(ch)) {
            lexeme[i++] = ch;
            while ((ch1 = fgetc(fp1)) != EOF && (isalpha(ch1) || isdigit(ch1))) {
                lexeme[i++] = ch1;
            }
            lexeme[i] = '\0';
            ungetc(ch1, fp1);

            int isKeyword = 0;
            for (j = 0; j < 15; j++) {
                if (strcmp(keywords[j], lexeme) == 0) {
                    isKeyword = 1;
                    break;
                }
            }

            if (isKeyword)
                fprintf(op, "\n%d %s Keyword %d", sr++, lexeme, line);
            else
                fprintf(op, "\n%d %s Identifier %d", sr++, lexeme, line);
        } else {
            fprintf(op, "\n%d %c Unrecognized_Symbol %d", sr++, ch, line);
        }
    }

    fclose(fp1);
    fclose(op);
    return 0;
}

