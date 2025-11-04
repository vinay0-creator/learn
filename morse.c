#include <stdio.h>
#include <string.h>

struct MorseMap {
    const char *morse;
    char alpha;
};

struct MorseMap code[] = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'}, 
    {"-----", '0'}, {".----", '1'}, {"..---", '2'},
    {"...--", '3'}, {"....-", '4'}, {".....", '5'},
    {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}
};

char morse_to_alpha(const char *morse) {
    for (int i = 0; i < sizeof(code)/sizeof(code[0]); i++) {
        if (strcmp(code[i].morse, morse) == 0)
            return code[i].alpha;
    }
    return '?'; // Unknown symbol
}

int main() {
    char input[1024];
    printf("Enter Morse code (use space between letters, / between words):\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");
    while (token) {
        if (strcmp(token, "/") == 0)
            printf(" ");
        else
            printf("%c", morse_to_alpha(token));
        token = strtok(NULL, " \n");
    }
    printf("\n");
    return 0;
}

