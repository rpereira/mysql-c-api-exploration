#include "utils.h"

#include <mysql.h>

void exit_with_error(MYSQL *mysql)
{
    fprintf(stderr, "%s\n", mysql_error(mysql));
    mysql_close(mysql);
    exit(EXIT_FAILURE);
}
