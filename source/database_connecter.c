#include<stdio.h>
#include "database_connecter.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{
   int i;
   for(i = 0; i<argc; i++) 
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("hello DB \n");
    return 0;
}


int connect()
{
    int rc;
    rc = sqlite3_open("Test.db", &database);
    if( rc ) 
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
        return 0;
    } 
    else 
    {
        fprintf(stdout, "Opened database successfully\n");
        return 1;
    }

    return 0;
}



int table_create()
{
    char *zErrMsg = 0;
    int rc;
    char *sql;
    
    sql =  "CREATE TABLE Library(" \
      "book_id INT PRIMARY KEY NOT NULL," \
      "book_NAME TEXT NOT NULL," \
      "author_NAME TEXT NOT NULL," \
      "genre TEXT NOT NULL," \
      "book_price INT NOT NULL );";

    rc = sqlite3_exec(database, sql, callback, 0, &zErrMsg);
    if(rc!=SQLITE_OK ) 
    {
        fprintf(stderr, "SQL error in create: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
    else 
    {
        fprintf(stdout, "Table created successfully\n");
    }

    return 0;     
}



int insert(int book_id,char *book_name,char *author_name,char *genre,int book_price)
{
    // printf("In insert function, rollnum[%d],name[%s], age [%d]\n", db[i].rollnum,db[i].name,db[i].age );
    int rc;
    char *zErrMsg;
    char sql[1024] ;
    sprintf(sql,"INSERT INTO Library (book_id,book_name,author_name,genre,book_price) VALUES ( %d , '%s' , '%s' , '%s' , %d);",book_id,book_name,author_name,genre,book_price);
    printf("Query to be executed: [%s]",sql);
    rc = sqlite3_exec(database, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) 
    {
        fprintf(stderr, "SQL error in insert: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } 
    else 
    {
        fprintf(stdout, "Records created successfully\n");
        return 1;
    }
    
    // return 0;  
}



int select()
{
    int rc;
    char *zErrMsg;
    const char* data = "select function called";
   
    char *sql = "SELECT * from Library;";
   
    rc = sqlite3_exec(database, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ) 
    {
      fprintf(stderr, "SQL error in select: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    } 
    else 
    {
      fprintf(stdout, "Operation done successfully\n");
    }
   
    return 0;
}


int close()
{
    printf("data base connection is closed\n");
    sqlite3_close(database);

    return 0;
}