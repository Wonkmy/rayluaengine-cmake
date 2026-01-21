#include <stdlib.h> // 添加此行以定义NULL
#include "../include/generic/dictionary.h"
#include <string.h>
void init(const char* text)
{
    char* cursor = (char*)text;
    char line[512];

    while (*cursor) {

        // 拷贝一行
        int len = 0;
        while (cursor[len] && cursor[len] != '\n') {
            line[len] = cursor[len];
            len++;
        }
        line[len] = '\0';

        if (len > 0) {
            sscanf(line, "%63s %255s",
                g_resources[g_resource_count].key,
                g_resources[g_resource_count].value);

            g_resource_count++;
        }

        // 跳到下一行
        cursor += len;
        if (*cursor == '\n') cursor++;
    }
}
char* get(const char* key)
{
    for (int i = 0; i < g_resource_count; i++) {
        if (strcmp(g_resources[i].key, key) == 0) {
            return g_resources[i].value;
        }
    }
    return NULL;
}