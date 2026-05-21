// 0x803236CC (88B) EControllerManager::Flush(void)

extern void* EControllerManager_table[4];  // 0x804FCF78

class EControllerManager {
public:
    static void Flush();
};

void EControllerManager::Flush() {
    void** p = EControllerManager_table;
    void** end = EControllerManager_table + 3;
    do {
        char* ctrl = (char*)*p;
        p++;
        char* vt = *(char**)(ctrl + 520);
        short adj = *(short*)(vt + 168);
        void* fn = *(void**)(vt + 172);
        ((void (*)(void*))fn)(ctrl + adj);
    } while ((int)p <= (int)end);
}
