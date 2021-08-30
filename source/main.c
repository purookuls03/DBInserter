#include<stdio.h>
#include "csv_reader.h"
#include "database_connecter.h"


int main()
{
    printf("Starting DBIntserter...\n");
    
    file_read();

    connect();

    table_create();
    
    display();

    // insert();

    select();

    close();

    return 0;
}