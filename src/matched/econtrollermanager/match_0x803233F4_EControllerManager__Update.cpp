// 0x803233F4 (88B) EControllerManager::Update(void)

extern void* EControllerManager_table[4];  // 0x804FCF78

class EControllerManager {
public:
    static void Update();
};

void EControllerManager::Update() {
    void** p = EControllerManager_table;
    void** end = EControllerManager_table + 3;
    do {
        char* ctrl = (char*)*p;
        p++;
        char* vt = *(char**)(ctrl + 520);
        short adj = *(short*)(vt + 176);
        void* fn = *(void**)(vt + 180);
        ((void (*)(void*))fn)(ctrl + adj);
    } while ((int)p <= (int)end);
}
