// 0x8003E00C (60B) GameEffectsManager::GetSingleton(void)

struct GameEffectsManager {
    char data[1];
    GameEffectsManager();
    static GameEffectsManager* GetSingleton();
};

extern GameEffectsManager* g_gem_instance;

GameEffectsManager* GameEffectsManager::GetSingleton() {
    if (!g_gem_instance) {
        g_gem_instance = new GameEffectsManager();
    }
    return g_gem_instance;
}
