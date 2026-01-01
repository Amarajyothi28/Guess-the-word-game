#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3   // attempts per word
#define WORD_COUNT 5     // total words to guess

int main() {
    // List of 5 words
    const char *words[WORD_COUNT] = {"strawberry", "parrot", "cricket", "code", "saturn"};
    // Matching clues for each word
    const char *clues[WORD_COUNT] = {
        "Iam a healthy fruit and iam in red colour ??",
        "It is a bird",
        "It ia an outdoor game ??",
        "What programmers write ??",
        "Iam a planet and i have rings around my body ??"
    };

    char guess[50];
    int score = 0;

    printf("=== Guess the Word Game ===\n");
    printf("You need to guess %d words!\n", WORD_COUNT);
    printf("You have %d attempts for each word.\n\n", MAX_ATTEMPTS);

    // Loop through all words
    for (int i = 0; i < WORD_COUNT; i++) {
        int attempts = MAX_ATTEMPTS;
        int correct = 0;

        printf("Word %d: Clue ? %s\n", i + 1, clues[i]);

        while (attempts > 0) {
            printf("Enter your guess: ");
            scanf("%49s", guess);

            if (strcmp(guess, words[i]) == 0) {
                printf("?? Correct! The word was '%s'.\n\n", words[i]);
                score++;
                correct = 1;
                break;
            } else {
                attempts--;
                if (attempts > 0) {
                    printf("? Wrong! Attempts left: %d\n", attempts);
                }
            }
        }

        if (!correct) {
            printf("?? Out of attempts! The word was '%s'.\n\n", words[i]);
        }
    }

    // Final score
    printf("=== Game Over ===\n");
    printf("You guessed %d out of %d words correctly.\n", score, WORD_COUNT);

    return 0;
}
