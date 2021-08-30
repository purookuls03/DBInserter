#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "csv_reader.h"
#include "database_connecter.h"

int count=0;

int file_read()
{
    printf("In Function File Read\n");
    FILE *fp;
    fp=fopen("library.csv","r");
    if(fp==NULL)
    {
        printf("File is empty\n");
        return 0;
    }
    char line[500];
    printf("Going to get Line\n");
    while (fgets(line, sizeof(line), fp)) 
    {
        printf("%s", line); 
        tokenize((char *)line);
    }
    fclose(fp);
    return 0;
}


int tokenize(char *line)
{
    printf("\nIn Tokenize count = %d\n",count);
    
    char comma[] = ",";
    char *token;

    token = strtok(line,comma);
    db[count].book_id=atoi(token);
    token = strtok(NULL,comma);
    strcpy(db[count].book_name,token);
    token = strtok(NULL,comma);
    strcpy(db[count].author_name,token);
    token = strtok(NULL,comma);
    strcpy(db[count].genre,token);
    token = strtok(NULL,comma);
    db[count].book_price=atoi(token);
    
    count++;
    printf("\nIn Tokenize count++ = %d\n",count);
    return 0;
}


int display()
{
    printf("\ncount = %d\n",count);
    for(int i=1;i<count;i++)
    {
        printf("book_id = %d, book_name = %s, author_name = %s, genre = %s, book_price = %d\n",db[i].book_id, db[i].book_name, db[i].author_name, db[i].genre, db[i].book_price);    

        insert(db[i].book_id,db[i].book_name,db[i].author_name,db[i].genre,db[i].book_price);
    }
   
    return 0;
}