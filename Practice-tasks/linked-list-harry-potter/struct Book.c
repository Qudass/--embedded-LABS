#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int year;
    struct Book* next;
};

struct Book* createBook(
    const char* title,
    float price,
    int pages,
    const char* language,
    float weight,
    int year
) {
    struct Book* book = (struct Book*)malloc(sizeof(struct Book));

    strcpy(book->title, title);
    book->price = price;
    book->pages = pages;
    strcpy(book->language, language);
    book->weight = weight;
    book->year = year;
    book->next = NULL;

    return book;
}

void printList(struct Book* head) {
    int i = 1;
    while (head != NULL) {
        printf("Book %d:\n", i);
        printf("  Title: %s\n", head->title);
        printf("  Price: %.2f\n", head->price);
        printf("  Pages: %d\n", head->pages);
        printf("  Language: %s\n", head->language);
        printf("  Weight: %.2f kg\n", head->weight);
        printf("  Year: %d\n\n", head->year);

        head = head->next;
        i++;
    }
}

void freeList(struct Book* head) {
    while (head != NULL) {
        struct Book* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Book* head = createBook(
        "Harry Potter and the Philosopher's Stone",
        25.99, 223, "English", 0.35, 1997
    );

    head->next = createBook(
        "Harry Potter and the Chamber of Secrets",
        26.99, 251, "English", 0.40, 1998
    );

    head->next->next = createBook(
        "Harry Potter and the Prisoner of Azkaban",
        27.99, 317, "English", 0.45, 1999
    );

    printf("Harry Potter Book Series:\n\n");
    printList(head);

    freeList(head);
    return 0;
}
