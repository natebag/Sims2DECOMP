typedef int UIScreenID;

class UIScreenManager {
public:
    void UnloadUIScreen(UIScreenID id);
};

extern UIScreenManager* g_screenManager;

class FAMTarget {
public:
    void UnloadScreen(void);
};

void FAMTarget::UnloadScreen(void) {
    g_screenManager->UnloadUIScreen(0x44);
}
