#define GameWidth 1280
#define GameHeight 720
#define FPS 60.0f
typedef struct GameEngine GameEngine;

struct GameEngine
{
    int screenWidth;
    int screenHeight;
    const char* windowTitle;
    void (*onload)(GameEngine* engine);
    void (*update)(GameEngine* engine,float dt);
    void (*draw)(GameEngine* engine);
    void (*destroy)(GameEngine* engine);
};

void GameEngine_Init(GameEngine* engine);
void onload(GameEngine* engine);
void update(GameEngine* engine, float dt);
void draw(GameEngine* engine);
void destroy(GameEngine* engine);

