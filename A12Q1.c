#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 7
#define ARRAY_SIZE 9

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_sorted(Node** bucket, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL || (*bucket)->data >= value) {
        newNode->next = *bucket;
        *bucket = newNode;
    } else {
        Node* current = *bucket;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void collect_and_print(Node* buckets[]) {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        Node* node = buckets[i];
        while (node) {
            printf("%d ", node->data);
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    printf("\n");
}

int main() {
    int array[ARRAY_SIZE] = {12, 45, 33, 87, 56, 9, 11, 7, 67};

    int max = array[0];
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (array[i] > max)
            max = array[i];
    }

    Node* buckets[BUCKET_COUNT] = {NULL};

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        int index = (array[i] * BUCKET_COUNT) / (max + 1);
        insert_sorted(&buckets[index], array[i]);
    }

    printf("Sorted array:\n");
    collect_and_print(buckets);

    return 0;
}
