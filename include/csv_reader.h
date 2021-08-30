struct student_record
{
        int book_id;
        char book_name[50];
        char author_name[30];
        char genre[20];
        int book_price;
};
struct student_record db[1000];




int file_read();

int tokenize(char *);

int display();