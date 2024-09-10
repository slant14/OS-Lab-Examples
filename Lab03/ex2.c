#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person {
    char *name;
    int age;
    float height;
};


struct Person *createPerson(char *name, int age, float height) {
    
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));

    if (newPerson == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

    
    newPerson->name = (char *)malloc(strlen(name) + 1);
    if (newPerson->name == NULL) {
        printf("Memory allocation for name failed!\n");
        free(newPerson); 
        exit(1);
    }
    strcpy(newPerson->name, name); 

    newPerson->age = age;
    newPerson->height = height;

    return newPerson;
}


void showPerson(struct Person *person) {
    if (person == NULL) return; 
    printf("Name: %s, Age: %d, Height: %.2f\n", person->name, person->age, person->height);
}


int main() {
    
    struct Person *friends[3];

    
    friends[0] = createPerson("Alice", 25, 5.5);
    friends[1] = createPerson("Bob", 30, 5.9);
    friends[2] = createPerson("Charlie", 28, 6.1);

    
    for (int i = 0; i < 3; i++) {
        showPerson(friends[i]);
    }

    
    for (int i = 0; i < 3; i++) {
        free(friends[i]->name); 
        free(friends[i]);       
    }

    return 0;
}
