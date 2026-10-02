#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int id;
  char fullName[50];
  char email[25];
} Student;

void prettyPrint(const Student *s) {
    if (!s) return;
    printf("Student {\n");
    printf("\t .id = %d,\n", s->id);
    printf("\t .fullName = \"%s\",\n", s->fullName);
    printf("\t .email = \"%s\"\n", s->email);
    printf("}\n");
}

// FIX 1: Return malloc'ed memory, not local array
char* generateRandomNames(int length) {
    if (length <= 0) length = 5;
    char* randomString = malloc(length + 1);
    if (!randomString) return NULL;

    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
       randomString[i] = letters[rand() % 26];
    }
    randomString[length] = '\0'; 
    return randomString;
}

// FIX 3: Return Student* (malloc'ed array) not local array
Student* loadFakeData(int count) {
    Student *dataset = malloc(sizeof(Student) * count);
    if (!dataset) return NULL;

    for (int i = 0; i < count; i++) {
        dataset[i].id = i + 1;

        // Generate name
        char *tempName = generateRandomNames(12 + rand() % 6); // 5-10 chars
        strncpy(dataset[i].fullName, tempName, sizeof(dataset[i].fullName)-1);
        dataset[i].fullName[sizeof(dataset[i].fullName)-1] = '\0';
        free(tempName);

        // Generate email - name@xxx.com
        char *part1 = generateRandomNames(5);
        char *part2 = generateRandomNames(3);
        snprintf(dataset[i].email, sizeof(dataset[i].email), "%s@%s.com", part1, part2);
        free(part1);
        free(part2);

        prettyPrint(&dataset[i]); // FIX 4: Pass address
    }
    return dataset;
}

int main() {
    srand(time(NULL)); // seed random

    int total = 10; // generate 10 for demo
    Student *data = loadFakeData(total);

    if (data) {
        //... use data...
        free(data); // FIX 5: Always free malloc
    }
    return 0;
}
