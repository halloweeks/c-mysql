#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>

int main() {
  MYSQL *connection;
  MYSQL_RES *results;
  MYSQL_ROW row;
  
  connection = mysql_init(NULL);
  
  if (!mysql_real_connect(connection, "127.0.0.1", "root", "1234", "test", 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(connection));
    exit(EXIT_FAILURE);
  }
  
  if (mysql_query(connection, "show tables")) {
    //fprintf(stderr, "%s\n", mysql_error(connection));
    exit(EXIT_FAILURE);
  }
  
  results = mysql_use_result(connection);
  // int num = mysql_num_rows(results);
  
  // output table name
  printf("MySQL Tables in mysql database:\n");
  while ((row = mysql_fetch_row(results)) != NULL) {
    printf("%s \n", row[0]);
  }
  
  // close connection
  mysql_free_result(results);
  mysql_close(connection);
  
  exit(EXIT_SUCCESS);
}
