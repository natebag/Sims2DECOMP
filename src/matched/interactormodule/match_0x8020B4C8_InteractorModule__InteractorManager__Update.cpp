// 0x8020B4C8 InteractorModule::InteractorManager::Update(float) (84B)

struct InteractorInputManager {
    void Update(float dt);
};

struct InteractorManager {
    void* vtable;
    
    void UpdateActivePlayerInteractors(float dt);
    void Update(float dt);
};

extern InteractorInputManager* g_interactorInputManager;

void InteractorManager::Update(float dt) {
    if (vtable) {
        g_interactorInputManager->Update(dt);
        UpdateActivePlayerInteractors(dt);
    }
}
