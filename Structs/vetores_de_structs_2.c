#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

typedef struct _book {
    char title[64];
    unsigned int pages;
    float price;
} Book;

Book *create_book(const char *title, const unsigned int pages, const float price){
    Book *book = (Book *) calloc(1, sizeof(Book));
    strcpy(book->title, title);
    book->pages = pages;
    book->price = price;
    return book;
}

void read_book(Book *book){
    printf("Título: %s\nNúmero de páginas: %d\nPreço: R$ %.2f\n", book->title, book->pages, book->price);
}

void update_book(Book *book, const char *new_title, const unsigned int new_pages, const float new_price){
    strcpy(book->title, new_title);
    book->pages = new_pages;
    book->price = new_price;
}

void delete_book(Book **book_ref){
    free(*book_ref);
    *book_ref = NULL;
}

Book *copy_book(Book *book){
    Book *copia = (Book *) calloc(1, sizeof(Book));
    strcpy(copia->title, book->title);
    copia->pages = book->pages;
    copia->price = book->price;
    return copia;
}

bool isEquals_book(Book book1, Book book2){
    if(strcmp(book1.title, book2.title) != 0){
        return true;
    }
    return false;
}

typedef struct _book_collection{
    Book **books;
    int capacity;
    int size;
} BookCollection;

BookCollection *create_book_collection(const int capacity){
    BookCollection *collection = (BookCollection *) calloc(1, sizeof(BookCollection));
    Book **books = (Book **) calloc(capacity, sizeof(Book*));
    collection->books = books;
    collection->capacity = capacity;
    collection->size = 0;
    return collection;
}

void read_book_collection(BookCollection *collection){
    for (int i = 0; i < collection->size; i++) {
        read_book(collection->books[i]);
    }
}

void append_book_to_collection(BookCollection **collection_ref, Book **book_ref){
    BookCollection *collection = *collection_ref;
    Book *book = copy_book(*book_ref);

    if(collection->size == collection->capacity){
        fprintf(stderr, "\nERROR: on fucntion 'append_book_to_collection'.\n");
        fprintf(stderr, "ERROR MESSAGE: The collection is already full.\n");
        exit(EXIT_FAILURE);
    }

    collection->books[collection->size++] = book;
}

void remove_book_from_collection(BookCollection **collectio_ref, unsigned int book_index){
    BookCollection *collection = *collectio_ref;
    if (book_index >= collection->size){
        fprintf(stderr, "\nERROR: on fucntion 'remove_book_from_collection'.\n");
        fprintf(stderr, "ERROR MESSAGE: The book index is out of range.\n");
        exit(EXIT_FAILURE);
    }
    delete_book(&collection->books[book_index]);
    collection->size--;
}

void delete_book_collection(BookCollection **collection_ref){
    BookCollection *collection = *collection_ref;
    for (int i = 0; i < collection->size; ++i) {
        delete_book(&collection->books[i]);
    }
    free(collection);
    collection = NULL;
}

int main(){

    BookCollection *collection = create_book_collection(3);
    Book *book1 = create_book("O Senhor dos Anéis - A Sociedade do Anel", 423, (float) 46.6);
    Book *book2 = create_book("O Senhor dos Anéis - As Duas Torres", 464, (float) 52.9);
    Book *book3 = create_book("O Senhor dos Anéis - O Retorno do Rei", 431, (float) 44.9);

    append_book_to_collection(&collection, &book1);
    append_book_to_collection(&collection, &book2);
    append_book_to_collection(&collection, &book3);

    read_book_collection(collection);

    remove_book_from_collection(&collection, 2);

    puts("------------------------");
    read_book_collection(collection);

    append_book_to_collection(&collection, &book3);

    puts("------------------------");
    read_book_collection(collection);

    return 0;
}