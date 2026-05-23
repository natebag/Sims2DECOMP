// 0x8020B654 InteractorModule::InteractorManager::GetSingleton(void) (60B)
struct InteractorManager;

extern void* __builtin_new(unsigned int size);
extern InteractorManager* InteractorManager__ctor(InteractorManager* self);

static InteractorManager* s_instance;  // in SDA

InteractorManager* InteractorManager__GetSingleton() {
    if (s_instance == 0) {
        s_instance = InteractorManager__ctor((InteractorManager*)__builtin_new(80));
    }
    return s_instance;
}
