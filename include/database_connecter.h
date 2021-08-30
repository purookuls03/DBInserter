
#include "sqlite3.h"

sqlite3 *database;

static int callback(void *, int , char **, char **);

int connect();

int table_create();

int insert(int ,char *,char *,char *,int );

int select();

int close();