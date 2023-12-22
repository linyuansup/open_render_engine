#include "main.h"

int main()
{
    int res = init_engine("C:\\Program Files\\POCALOID5ESV\\Common");
    if (res != 0)
    {
        printf("Error: %d\n", res);
        return res;
    }
    printf("Success init engine!\n");
    int dbNum = get_database_count();
    printf("Database count: %d\n", dbNum);
    struct database *dbs = get_databases();
    for (int i = 0; i < dbNum; i++)
    {
        printf("Database %d: %s\n", dbs[i].id, dbs[i].name);
    }
    return render("D:\\93601\\Desktop\\sequence.json", "D:\\93601\\Desktop\\output.wav");
}