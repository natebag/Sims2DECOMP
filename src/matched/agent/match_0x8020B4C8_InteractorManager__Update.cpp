// 0x8020B4C8 InteractorManager::Update (64B)

struct InteractorManager {
    void* vtable;
    
    void Update(float dt);
};

extern "C" void SomeGlobalFunc(void*);
extern "C" void AnotherFunc(InteractorManager*, float);
extern void* gSomeGlobal;

void InteractorManager::Update(float dt) {
    if (vtable) {
        SomeGlobalFunc(gSomeGlobal);
        AnotherFunc(this, dt);
    }
}
