#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
	MYSQL *connection;
	MYSQL_RES *results;
	MYSQL_ROW row;
	
	connection = mysql_init(NULL);
	
	// hostname, username, password, database name
	if (!mysql_real_connect(connection, "127.0.0.1", "root", NULL, NULL, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(connection));
		exit(EXIT_FAILURE);
	}
	
	if (mysql_query(connection, "SHOW DATABASES")) {
		fprintf(stderr, "%s\n", mysql_error(connection));
		exit(EXIT_FAILURE);
	}
	
	results = mysql_use_result(connection);
	// int num = mysql_num_rows(results);
	
	printf("MySQL Databases:\n");
	while ((row = mysql_fetch_row(results)) != NULL) {
		printf("[%s]\n", row[0]);
	}
	
	// close connection
	mysql_free_result(results);
	mysql_close(connection);
	exit(EXIT_SUCCESS);
}
