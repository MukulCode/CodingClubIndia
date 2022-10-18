// Header Files
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Macros
#define NAME_SIZE 50
#define MAX_NO_OF_USERS 50
#define DATA_FILE "data.txt"
#define EASY "easy.txt"
#define MEDIUM "medium.txt"
#define HARD "hard.txt"

// Structure to pass around, represents the LOGGED-IN user
struct User
{
    char username[NAME_SIZE], name[NAME_SIZE];
    int level_easy, level_med, level_hard, points, coins;
};
#define User struct User

// Function Declarations
void welcome_screen();
void login();
User *user_exists(char[]);
User *create_user(char[]);
void main_menu(User *);
void about();
void start(User *);
int get_level(User *, int);
int get_difficulty();
int play(int, int, User *);
float get_percentage(int);
char *get_word(int);
char *select_from_easy();
char *select_from_medium();
char *select_from_hard();
void display_on_screen(int, int, int, int, char[], char[], int, int);
void display_practice(int, char[], char[], int, int);
void print_string(char[], char[], int);
void practice();
void leaderboard();
void help();
void reset_user(User *);
void update(User *);
void clear_buffer();
void str_replace(char str[], char old, char New);
int search_int(int arr[], int size, int key);
int get_distinct(char orig[], char New[]);
int search_char(char arr[], int size, char key);
void gotoxy(int, int);
void green();
void cyan();
void yellow();
void reset();
void box();

int main()
{
    int option;
    do
    {
        welcome_screen();

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            login();
            break;
        case 2:
            about();
            break;
        case 3:
            printf("\t\bExiting");
            break;
        default:
            printf("\t\bInvalid Input");
        }
    } while (option != 3);
    gotoxy(0, 36);
    return 0;
}

// Displays Welcome Screen
void welcome_screen()
{
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    yellow();
    printf("\t\t\t\tWELCOME TO THE RESCUE GAME \n\n\n\n");
    reset();
    printf("\t\t\t1. Play\n\n");
    printf("\t\t\t2. About\n\n");
    printf("\t\t\t3. Exit\n\n");
    printf("\n\n\n\t\tSelect an Option to Continue : ");
}

// Logs in the user to enter in game
void login()
{
    gotoxy(7, 25);
    char username[NAME_SIZE];
    printf("Enter your username\n");
    clear_buffer();
    gotoxy(7, 26);
    scanf("%s", username);

    User *user = user_exists(username);

    if (user != NULL)
    {
        printf("\t\bUser Found");
        main_menu(user);
    }
    else
    {
        user = create_user(username);
        if (user != NULL)
        {
            printf("\t\bUser Created Successfully");
            main_menu(user);
        }
        else
        {
            printf("\t\bSome Error Occurred");
        }
    }
}

// Function to check if any user is present with the given username, returns the User Structure if the user exists or else returns
User *user_exists(char username[])
{
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    User *user = (User *)malloc(sizeof(User));

    if (fptr != NULL)
    {
        char str[NAME_SIZE];
        while (fscanf(fptr, "%s %s %d %d %d %d %d", user->username, user->name, &user->level_easy, &user->level_med, &user->level_hard, &user->points, &user->coins) == 7)
        {
            if (strcmp(user->username, username) == 0)
            {
                fclose(fptr);
                return user;
            }
        }

        fclose(fptr);
        return NULL;
    }
    return NULL; // When fptr is NULL
}

User *create_user(char username[])
{
    FILE *fptr = fopen(DATA_FILE, "a");

    User *user = (User *)malloc(sizeof(User));

    if (fptr != NULL)
    {
        char name[NAME_SIZE];
        printf("\t\b-------------------------");
        printf("\n\t\bCreating User with the username %s\n", username);
        printf("\t\bEnter your name: ");
        gotoxy(7, 30);
        clear_buffer();
        scanf("%[^\n]s", name);

        //  replace blank space in name by _ (underscore ASCII 95)
        str_replace(name, ' ', '_');

        // username name level_easy level_med level_hard points coins
        fprintf(fptr, "\n%s %s %d %d %d %d %d", username, name, 1, 1, 1, 0, 0);
        fclose(fptr);

        // Initializing structure
        strcpy(user->username, username);
        strcpy(user->name, name);
        user->level_easy = user->level_med = user->level_hard = 1;
        user->points = user->coins = 0;

        return user;
    }
    return NULL;
}

// Prafful
void main_menu(User *user)
{
    int option;
    do
    {
        system("cls");
        box();
        gotoxy(7, 7);
        printf("\n\n\n");
        yellow();
        printf("\t\t\t\tWELCOME TO THE RESCUE GAME --> ");
        cyan();

        int len = strlen(user->username);
        for (int i = 0; i < len; i++)
        {
            if (user->username[i] >= 97 && user->username[i] <= 122)
                printf("%c", user->username[i] - 32);
        }
        printf("\n\n");

        reset();
        printf("\t\t\t1. Start\n\n");
        printf("\t\t\t2. Practice\n\n");
        printf("\t\t\t3. Leaderboard\n\n");
        printf("\t\t\t4. Help\n\n");
        printf("\t\t\t5. Reset\n\n");
        printf("\t\t\t6. Exit\n\n");
        printf("\n\n\n\t\tSelect an Option to Continue : ");

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start(user);
            break;
        case 2:
            practice();
            break;
        case 3:
            leaderboard();
            break;
        case 4:
            help();
            break;
        case 5:
            reset_user(user);
            break;      
        default:
            printf("\n\t\bInvalid Input");
            break;
        }
    } while (option != 6);
}

// Displays About Section of the Game
void about()
{
    int option;
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    yellow();
    printf("\t\t\t\t\t\tABOUT\n\n");
    reset();
    printf("\t\bRescue game is a software that will the test the participant's general knowledge and guessing skills.There \n\t\bwill be certain number levels the user has to clear to save his friend if user fails to guess correct letter \n\t\bfor certain number of times in each level then user losses his friend.\n");
    green();
    printf("\n\n\t\t\tpress 1 to return : ");
    reset();
    do
    {
        scanf("%d", &option);
        if (option != 1)
        {
            printf("\tInvalid Input");
            printf("\n\n\t\t\tPress 1 to return : ");
        }
    } while (option != 1);
}

void start(User *user)
{
    int difficulty = get_difficulty();
    int level = get_level(user, difficulty);

    for (; level <= 10;)
    {
        int val = play(level, difficulty, user);
        if (val)
        {
            level++;
        }
        
        int ch;
        printf("\n\n\t\bPress 1 if you want to continue to the next level OR else ANOTHER NUMBER to EXIT ");
        scanf("%d", &ch);

        if (ch != 1)
            break;
    }

    // check if level is 11 game won else user exited
    if (level == 11)
    {
        green();
        printf("\t\bYou have WON the GAME!!!!!!!!");
        reset();
    }
    else
    {
        yellow();
        printf("\t\bThanks For Playing");
        reset();
    }

    if (difficulty == 0)
        user->level_easy = level;
    else if (difficulty == 1)
        user->level_med = level;
    else
        user->level_hard = level;

    // update userdata
    update(user);
}

int get_level(User *user, int difficulty)
{
    if (difficulty == 0)
        return user->level_easy;
    if (difficulty == 1)
        return user->level_med;
    return user->level_hard;
}

// Returns 0 if Easy, 1 if Medium, 2 if Hard is selected
int get_difficulty()
{
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    green();
    printf("\t\t\t\t\t\bTHE RESCUE GAME");
    reset();
    printf("\n\n\n");
    yellow();
    printf("\t\bChoose the Difficulty level");
    reset();
    printf("\n\n\t\b1. Easy ");
    printf("\n\t\b2. Medium ");
    printf("\n\t\b3. Hard");
    cyan();
    printf("\n\n\t\bEnter your choice : ");
    reset();

    int c;
    scanf("%d", &c);
    while (c < 1 || c > 3)
    {
        printf("\t\bInvalid Choice");
        scanf("%d", &c);
    }

    return c - 1;
}

int play(int level, int difficulty, User *user)
{

    char str[30];
    strcpy(str, get_word(difficulty));

    int length = 0;
    length = strlen(str);

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 10)
            str[i] = 0;
    }

    int no_of_removed = ceil(get_percentage(level) * length);

    int len;
    len = no_of_removed;
    int numberOfDistinct;

    char distinct[length];

    numberOfDistinct = get_distinct(str, distinct);

    int removed_index[no_of_removed];
    char removed_char[no_of_removed];

    srand(time(0));
    for (int i = 0; i < no_of_removed; i++)
    {
        int random = rand() % numberOfDistinct;
        int pos = search_int(removed_index, i, random);

        if (pos == -1)
            removed_index[i] = random;
        else
            i--;
    }

    for (int i = 0; i < no_of_removed; i++)
        removed_char[i] = distinct[removed_index[i]];

    int attempts = 4;

    display_on_screen(difficulty, user->coins, user->points, level, str, removed_char, len, attempts);

    while (attempts != 0 && no_of_removed != 0)
    {
        char entered;
        printf("\n\t\bEnter your guess");
        clear_buffer();
        printf("\n\t\b");
        scanf("%c", &entered);

        if (entered == '1')
            if (user->coins >= 100)
            {
                no_of_removed--;
                char temp;
                for (int i = 0; i < len; i++)
                    if (removed_char[i] != '-')
                    {
                        temp = removed_char[i];
                        removed_char[i] = '-';
                        break;
                    }
                printf("\t\bCharacter is %c", temp);
                user->coins -= 100;
            }
            else
                printf("\t\bYou Don't have ENOUGH COINS");

        if (entered == '2')
            if (user->coins >= 500)
            {
                user->coins -= 500;
                printf("\t\bSkipping Level");
                printf("\n\t\bPress Any Key To Continue...");
                getch();
                return 1;
            }
            else
                printf("\t\bYou Don't have ENOUGH COINS");

        int pos = search_char(removed_char, len, entered);
        
        if (entered != '1'&&entered!='2')
            if (pos == -1)
            {
                attempts--;
                printf("\a\t\bWrong Attempt");
            }
            else
            {
                no_of_removed--;
                removed_char[pos] = '-';
                printf("\t\bYou Guessed Correctly");
            }
        printf("\n\t\bPress any key to continue.....");
        getch();
        
        display_on_screen(difficulty, user->coins, user->points, level, str, removed_char, len, attempts);
    }

    printf("\n\t\bYou ");
    if (attempts)
    {
        green();
        printf("Won");
        reset();
        printf(" The Round");
        // Points Update

        int points = 10 * (difficulty + 1) + 5 * attempts;

        user->points += points;
        user->coins += 10 * attempts;

        printf("\n\n\t\bYou Gained %d Points", points);
        printf("\n\n\t\bPress any key to continue...");
        getch();

        return 1;
    }
    else
    {
        cyan();
        printf("Lost The Round\n");
        reset();
        printf("\t\bThe Correct Word was ");
        yellow();
        printf("%s",str);
        reset();
        printf("\n\t\bPress any key to continue...");
        getch();

        return 0;
    }
}

float get_percentage(int level)
{
    if (level > 5)
        return 0.50;
    return 0.25;
}

char *get_word(int difficulty)
{
    if (difficulty == 0)
    {
        // selecting word from easy text file
        return select_from_easy();
    }
    else if (difficulty == 1)
    {
        // selecting word from medium text file
        return select_from_medium();
    }
    else
    {
        // selecting word from hard text file
        return select_from_hard();
    }

    return NULL; // this case can never be reached.
}

char *select_from_easy()
{

    FILE *fptr;
    fptr = fopen(EASY, "r");

    if (fptr == NULL)
    {
        printf("\t\bCan not open file.\n");
    }
    else
    {
        char *words = (char *)malloc(30 * sizeof(char));

        int i = 0, ran = 0;

        srand(time(NULL));

        for (; fgets(words, 30, fptr); i++)
            ;

        ran = rand() % i;
        rewind(fptr);

        for (i = 0; i <= ran; i++)
            fgets(words, 30, fptr);

        fclose(fptr);
        return words;
    }
}

char *select_from_medium()
{
    FILE *fptr;
    fptr = fopen(MEDIUM, "r");

    if (fptr == NULL)
    {
        printf("\t\bCan not open file.\n");
    }
    else
    {
        char *words = (char *)malloc(30 * sizeof(char));

        int i = 0, ran = 0;

        srand(time(NULL));

        for (; fgets(words, 30, fptr); i++)
            ;

        ran = rand() % i;
        rewind(fptr);

        for (i = 0; i <= ran; i++)
            fgets(words, 30, fptr);

        fclose(fptr);
        return words;
    }
}

char *select_from_hard()
{
    FILE *fptr;
    fptr = fopen(HARD, "r");

    if (fptr == NULL)
    {
        printf("\t\bCan not open file.\n");
    }
    else
    {
        char *words = (char *)malloc(30 * sizeof(char));

        int i = 0, ran = 0;

        srand(time(NULL));

        for (; fgets(words, 30, fptr); i++)
            ;

        ran = rand() % i;
        rewind(fptr);

        for (i = 0; i <= ran; i++)
            fgets(words, 30, fptr);

        fclose(fptr);
        return words;
    }
}

void display_on_screen(int diff, int coins, int points, int level, char word[], char removed_char[], int no_of_removed, int no_of_attempts)
{
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    yellow();
    printf("\t\t\t\t\t\t  THE RESCUE GAME");
    printf("\n\n\n");
    reset();
    green();

    char difficulty[20];
    switch (diff)
    {
    case 0:
        strcpy(difficulty, "Easy");
        break;
    case 1:
        strcpy(difficulty, "Medium");
        break;
    case 2:
        strcpy(difficulty, "Hard");
        break;
    }
    printf("\t\bDifficulty-->%s", difficulty);

    reset();
    printf("\t\t\t\t\t\t\t\t\t\tPoints-->%d", points);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tCoins-->%d", coins);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tLevel-->%d", level);
    cyan();
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\b\b100 Coins-->REVEAL 1 LETTER(1)");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\b\b500 Coins-->SKIP LEVEL(2)");
    reset();
    printf("\n\n\n\n\t\t\t\tThe Word is :");

    print_string(word, removed_char, no_of_removed);

    green();
    printf("\n\n\t\bAttempts Left : %d ", no_of_attempts);
    reset();
}

void print_string(char word[], char removed_letters[], int no_of_removed)
{
    for (int i = 0; word[i]; i++)
    {
        int pos = search_char(removed_letters, no_of_removed, word[i]);
        printf("%c", pos == -1 ? word[i] : '_');
    }
    printf("\n");
}

void practice()
{
    int check = 1;
    while (check==1)
    {
        srand(time(0));
        int difficulty = rand() % 3;
        char str[30];
        strcpy(str, get_word(difficulty)); // word will be later taken from a file

        int length = 0;
        length = strlen(str);

        for (int i = 0; str[i]; i++)
            if (str[i] == 10)
                str[i] = 0;

        int no_of_removed = ceil(.50 * length);

        int len;
        len = no_of_removed;
        int numberOfDistinct;

        char distinct[length];

        numberOfDistinct = get_distinct(str, distinct);

        int removed_index[no_of_removed];
        char removed_char[no_of_removed];

        srand(time(0));
        for (int i = 0; i < no_of_removed; i++)
        {
            int random = rand() % numberOfDistinct;
            int pos = search_int(removed_index, i, random);

            if (pos == -1)
                removed_index[i] = random;
            else
                i--;
        }

        for (int i = 0; i < no_of_removed; i++)
            removed_char[i] = distinct[removed_index[i]];

        int attempts = 4;

        display_practice(difficulty, str, removed_char, len, attempts);

        while (attempts != 0 && no_of_removed != 0)
        {
            char entered;
            printf("Enter your guess\n");
            clear_buffer();
            printf("\t\b");
            scanf("%c", &entered);

            int pos = search_char(removed_char, len, entered);
            if (pos == -1)
            {
                attempts--;
                printf("\t\b\aWrong Attempt");
            }
            else
            {
                no_of_removed--;
                removed_char[pos] = '-';
                printf("\t\bYou Guessed Correctly");
            }
            printf("\n");
            printf("\t\bPress any key to continue.....");
            getch();
            display_practice(difficulty, str, removed_char, len, attempts);
        }

        printf("\n\t\bYou ");
        if (attempts)
        {
            green();
            printf("Won The round");
        }
        else
        {
            cyan();
            printf("Lost The Round");
        }
        reset();
        printf("\n\n\t\bPress 1 if you want to continue to the next level OR Anything else to EXIT ");
        scanf("%d", &check);
    }
}

void display_practice(int diff, char word[], char removed_char[], int no_of_removed, int no_of_attempts)
{
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    yellow();
    printf("\t\t\t\t\tTHE RESCUE GAME");
    printf("\n\n\n");
    reset();
    green();

    char difficulty[20];
    switch (diff)
    {
    case 0:
        strcpy(difficulty, "Easy");
        break;
    case 1:
        strcpy(difficulty, "Medium");
        break;
    case 2:
        strcpy(difficulty, "Hard");
        break;
    }
    printf("\t\bDifficulty-->%s", difficulty);

    reset();
    printf("\n\n\n\n\t\t\t\t\bThe Word is :");

    print_string(word, removed_char, no_of_removed);

    green();
    printf("\n\n\t\bAttempts Left : %d ", no_of_attempts);
    reset();
}

void leaderboard()
{
    User u[MAX_NO_OF_USERS];
    FILE *ptr;

    ptr = fopen(DATA_FILE, "r");
    int len;
    for (len = 0; (fscanf(ptr, "%s %s %d %d %d %d %d", u[len].username, u[len].name, &u[len].level_easy, &u[len].level_med, &u[len].level_hard, &u[len].points, &u[len].coins) != EOF);)
    {
        len++;
    }
    fclose(ptr);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (u[i].points < u[j].points)
            {
                User temp;
                temp = u[i];
                u[i] = u[j];
                u[j] = temp;
            }
        }
    }
    system("cls");
    box();
    gotoxy(7, 7);
    yellow();
    printf("\n\n\n\t\t\t\t\t\t\t\bLEADERBOARD\n\n");
    cyan();
    printf("\t\t\t\t\bRANK\t\tUSERNAME\t\tNAME\t\tPOINTS\n\n");
    reset();

    int x = 32, y = 14; // x,y coordinates depend upon ide
    for (int i = 0; i < len; i++)
    {
        gotoxy(x, y);
        printf("%d", i + 1);
        gotoxy(x + 16, y);
        printf("%s", u[i].username);
        gotoxy(x + 40, y);
        printf("%s", u[i].name);
        gotoxy(x + 56, y);
        printf("%d", u[i].points);
        y++;
    }
    green();
    printf("\n\n\t\tPress 1 to return : ");
    reset();

    int option;
    while (option != 1)
    {
        scanf("%d", &option);
        if (option != 1)
            printf("\n\n\t\tInvalid Choice");
    }
}

void help()
{
    system("cls");
    box();
    gotoxy(7, 7);
    printf("\n\n\n");
    yellow();
    printf("\t\t\t\t\t\t\tHELP\n\n");
    reset();
    printf("\t\bIn this game the user has to clear to all levels to save his/her friend. In each level a word is displayed on\n\t\bthe screen with some of its letters replace with blanks the user has to guess the letters one by one from its\n\t\bkeyboard after type the letter the user hit the enter to check that letter-");
    cyan();
    printf("\n\n\t\b1. Correct letter->");
    reset();
    printf(" The letter replace its blanks in the world.");
    cyan();
    printf("\n\n\t\b2. Incorrect letter->");
    reset();
    printf(" In this game the user gets certain number of chances if the user enter the incorrect\n\t\bletter then its no. of chances become less by 1.");
    printf("\n\n\t\bIf the user guessed the word correctly before using all the chances then the user goes to next level.");
    cyan();
    printf("\n\n\t\bCoins");
    reset();
    printf("\n\n\t\bIf the user guessed the correct word then user will get coins in multiple of 10 of attempts left");
    cyan();
    printf("\n\n\t\bPractice mode");
    reset();
    printf("\n\n\t\bIn practice mode the user can pactice the words to improve its skills.");
    green();
    printf("\n\n\t\t\t\bPress 1 to return : ");
    reset();

    int option;
    do
    {

        scanf("%d", &option);
        if (option != 1)
        {
            printf("\t\bInvalid Input");
            printf("\n\n\t\t\t\bPress 1 to return : ");
        }
    } while (option != 1);
}

// function to update user data
void update(User *user)
{

    User *u1 = (User *)malloc(sizeof(User));

    FILE *fptr, *fptr1;
    fptr = fopen(DATA_FILE, "r");
    fptr1 = fopen("tempFile.txt", "w");

    int found = 0;

    while (fscanf(fptr, "%s %s %d %d %d %d %d", u1->username, u1->name, &u1->level_easy, &u1->level_med, &u1->level_hard, &u1->points, &u1->coins) == 7)
    {

        if (strcmp(u1->username, user->username) == 0)
        {
            u1->level_easy = user->level_easy;
            u1->level_med = user->level_med;
            u1->level_hard = user->level_hard;
            u1->points = user->points;
            u1->coins = user->coins;
        }

        fprintf(fptr1, "\n%s %s %d %d %d %d %d", u1->username, u1->name, u1->level_easy, u1->level_med, u1->level_hard, u1->points, u1->coins);
    }

    fclose(fptr1);
    fclose(fptr);
    remove(DATA_FILE);
    rename("tempFile.txt", DATA_FILE);
}

// function to reset user data
void reset_user(User *user)
{
    system("cls");
    box();
    gotoxy(7, 7);
    int ch;
    reset();
    printf("\n\n\t\t\t\bEnter 1 if you really want to reset the user data ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        yellow();
        printf("\n\n\t\t\t\bResetting User......");
        // to change in structure data
        reset();
        user->coins = 0;
        user->level_easy = 1;
        user->level_med = 1;
        user->level_hard = 1;
        user->points = 0;

        // to change in file
        User *u1 = (User *)malloc(sizeof(User));

        FILE *fptr, *fptr1;
        fptr = fopen(DATA_FILE, "r");
        fptr1 = fopen("tempFile.txt", "w");

        while (fscanf(fptr, "%s %s %d %d %d %d %d", u1->username, u1->name, &u1->level_easy, &u1->level_med, &u1->level_hard, &u1->points, &u1->coins) == 7)
        {

            if (strcmp(u1->username, user->username) == 0)
            {
                u1->level_easy = 1;
                u1->level_med = 1;
                u1->level_hard = 1;
                u1->points = 0;
                u1->coins = 0;
            }

            fprintf(fptr1, "\n%s %s %d %d %d %d %d", u1->username, u1->name, u1->level_easy, u1->level_med, u1->level_hard, u1->points, u1->coins);
        }

        fclose(fptr1);
        fclose(fptr);
        remove(DATA_FILE);
        rename("tempFile.txt", DATA_FILE);
        printf("\n\n\t\t\t\bUser Has Been Resetted Successfully");
    }
    else
        printf("\n\n\t\t\t\bGoing Back To Main Menu");
    printf("\n\n\t\t\t\bPress any key to continue...");
    getch();
}

void clear_buffer()
{
    // Flushes STDIN (Standarad Input) reccomended to use this before consecutive string input
    fflush(stdin);
}

// Replace every instance of 'old' character witht the 'New' character in the given string
void str_replace(char str[], char old, char New)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == old)
            str[i] = New;
}

int search_int(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int get_distinct(char orig[], char New[])
{
    int k = 0;
    for (int i = 0; orig[i]; i++)
    {
        int pos = search_char(New, k, orig[i]);
        if (pos == -1)
        {
            New[k] = orig[i];
            k++;
        }
    }
    return k;
}

int search_char(char arr[], int size, char key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

void gotoxy(int col, int row)
{
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(hstdout, position);
}

// Changes Pen Color to Green
void green()
{
    printf("\033[0;32m");
}

// Changes Pen Color to Blue
void cyan()
{
    printf("\033[0;36m");
}

// Changes Pen Color to Yellow
void yellow()
{
    printf("\033[1;33m");
}

// Resets Pen Color to Default
void reset()
{
    printf("\033[0m");
}

void box()
{
    int r, c; // row and column
    yellow();
    gotoxy(5, 5);
    printf("%c", 218);
    for (c = 5; c <= 115; c++)
    {
        printf("%c", 196);
    }
    printf("%c", 191);
    gotoxy(5, 5);
    for (r = 6; r <= 35; r++)
    {
        gotoxy(5, r);
        printf("%c", 179);
    }
    gotoxy(5, 35);
    printf("%c", 192);
    for (r = 6; r <= 35; r++)
    {
        gotoxy(117, r);
        printf("%c", 179);
    }
    gotoxy(117, 35);
    printf("%c", 217);
    for (c = 6; c <= 116; c++)
    {
        gotoxy(c, 35);
        printf("%c", 196);
    }
}
