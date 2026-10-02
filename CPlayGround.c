#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
  int id;
  char subject[50];
  int marks;
} Grade;

char *Subject[] = {
    "Subject-1",
    "Subject-2",
    "Subject-3",
    "Subject-4",
    "Subject-5",
    "Subject-6"
};
    
typedef struct {
  int id;
  char fullName[50];
  char email[25];
  Grade grade;
} Student;

void prettyPrint(const Student *s) {
    if (!s) return;
    printf("Student {\n");
    printf("\t .id = %d,\n", s->id);
    printf("\t .fullName = \"%s\",\n", s->fullName);
    printf("\t .email = \"%s\"\n", s->email);
    printf("\t ->grade.subject = \"%s\"\n", s->grade.subject);
    printf("\t ->marks.marks = \"%d\"\n", s->grade.marks);
    printf("}\n");
}

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
        char *part1 = generateRandomNames(8);
        char *part2 = generateRandomNames(4);
        snprintf(dataset[i].email, sizeof(dataset[i].email), "%s@%s.com", part1, part2);
        free(part1);
        free(part2);
        
        dataset[i].grade.id = i + 1;
        strcpy(dataset[i].grade.subject, Subject[rand() % 6]);
        dataset[i].grade.marks = rand() % 101; // 0-100, not rand()*100

        prettyPrint(&dataset[i]); 
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
