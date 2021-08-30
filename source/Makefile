home = "C:\Users\Dell\Desktop\language C\PROJECTS\DBInserter_project"
library_path = -L$(home)"\lib"
library = -lsqlite3
include = -I$(home)"\include"
Command = gcc
binary_name = db
source_file = main.c csv_reader.c database_connecter.c
db: 
	$(Command) -o $(binary_name) $(source_file)  $(include) $(library_path) $(library)
	
