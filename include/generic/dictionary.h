#define MAX_ITEMS 128
#include <string.h>
typedef struct {
    char key[64];
    char value[256];
} ResourceItem;
void init(const char* text);
char* get(const char* key);
static ResourceItem g_resources[MAX_ITEMS];
static int g_resource_count = 0;