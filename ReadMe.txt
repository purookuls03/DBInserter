Project_name : DBInserter

DBInserter is implemented in C. DbInserter connects to sqlite database, and it insert the records given in "file.csv" into database. 
1. As of now it DBInserter works for belowtable:

 "CREATE TABLE Library(" \
      "book_id INT PRIMARY KEY NOT NULL," \
      "book_NAME TEXT NOT NULL," \
      "author_NAME TEXT NOT NULL," \
      "genre TEXT NOT NULL," \
      "book_price INT NOT NULL );";

2. This pick csv file from hardcoded path "library.csv" in source folder. Sample csv is also given.

3. Sqlite3, Mingw and visual studio code should already be installed at your machine, prior to compiling and executing this project.

4. This project is only compitable with sqlite3 database, and it test.db created in source folder only. 

5. To comile download this project in any location at your machine, and change the "home" path given in Makefile located in source folder.

6. For compling at windows through mingw use "mingw32-make".