#define GameWidth 1280
#define GameHeight 720
typedef struct GameEngine GameEngine;

struct GameEngine
{
    int screenWidth;
    int screenHeight;
    const char* windowTitle;
    void (*onload)(GameEngine* engine);
    void (*update)(GameEngine* engine);
    void (*draw)(GameEngine* engine);
    void (*destroy)(GameEngine* engine);
};

// Function prototypes
void GameEngine_Init(GameEngine* engine);
void onload(GameEngine* engine);
void update(GameEngine* engine);
void draw(GameEngine* engine);
void destroy(GameEngine* engine);

