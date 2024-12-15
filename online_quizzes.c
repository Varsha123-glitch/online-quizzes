#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NUM_QUESTIONS 5
#define TIME_LIMIT 60 // Time limit in seconds for the entire quiz

// Structure to hold a question and its details
typedef struct {
    char question[256];
    char options[4][100];
    char correctOption;
} QuizQuestion;

void loadQuestions(QuizQuestion questions[]);
void startQuiz(QuizQuestion questions[]);

int main() {
    QuizQuestion questions[NUM_QUESTIONS];
    loadQuestions(questions);
    printf("Welcome to the Advanced Online Quiz!\n\n");
    startQuiz(questions);
    return 0;
}

void loadQuestions(QuizQuestion questions[]) {
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "A. Berlin");
    strcpy(questions[0].options[1], "B. Madrid");
    strcpy(questions[0].options[2], "C. Paris");
    strcpy(questions[0].options[3], "D. Rome");
    questions[0].correctOption = 'C';

    strcpy(questions[1].question, "Which programming language is known as the mother of all languages?");
    strcpy(questions[1].options[0], "A. Python");
    strcpy(questions[1].options[1], "B. C");
    strcpy(questions[1].options[2], "C. Java");
    strcpy(questions[1].options[3], "D. Pascal");
    questions[1].correctOption = 'B';

    strcpy(questions[2].question, "What is 2 + 2?");
    strcpy(questions[2].options[0], "A. 3");
    strcpy(questions[2].options[1], "B. 4");
    strcpy(questions[2].options[2], "C. 5");
    strcpy(questions[2].options[3], "D. 6");
    questions[2].correctOption = 'B';

    strcpy(questions[3].question, "Which planet is known as the Red Planet?");
    strcpy(questions[3].options[0], "A. Earth");
    strcpy(questions[3].options[1], "B. Venus");
    strcpy(questions[3].options[2], "C. Mars");
    strcpy(questions[3].options[3], "D. Jupiter");
    questions[3].correctOption = 'C';

    strcpy(questions[4].question, "What is the chemical symbol for water?");
    strcpy(questions[4].options[0], "A. H2O");
    strcpy(questions[4].options[1], "B. CO2");
    strcpy(questions[4].options[2], "C. O2");
    strcpy(questions[4].options[3], "D. NaCl");
    questions[4].correctOption = 'A';
}

void startQuiz(QuizQuestion questions[]) {
    int score = 0;
    char answer;
    time_t startTime, currentTime;

    printf("You have %d seconds to complete the quiz.\n\n", TIME_LIMIT);
    time(&startTime);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        time(&currentTime);
        if (difftime(currentTime, startTime) > TIME_LIMIT) {
            printf("Time's up! The quiz is over.\n\n");
            break;
        }

        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        answer = toupper(answer);

        if (answer >= 'A' && answer <= 'D') {
            if (answer == questions[i].correctOption) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Wrong! The correct answer was %c.\n", questions[i].correctOption);
            }
        } else {
            printf("Invalid option. Moving to the next question.\n");
        }
    }

    printf("\nQuiz Over! Your total score: %d/%d\n", score, NUM_QUESTIONS);
}
