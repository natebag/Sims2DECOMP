// 0x80328394 (88 bytes)
typedef unsigned int uint;
typedef unsigned long ulong;

struct EFile;
struct EResourceManager {
    char _pad[0xD20];
    void *Alloc(ulong size, uint group);
};
extern EResourceManager g_soundeventman;

struct ERSoundEvent {
    char _pad[52];
    ERSoundEvent(void);
    void Load(EFile *file);
};

inline void *operator new(uint, void *p) { return p; }

struct ESoundEventManager {
    ERSoundEvent *AllocateAndLoadResource(EFile *file, uint id1, uint id2);
};

ERSoundEvent *ESoundEventManager::AllocateAndLoadResource(EFile *file, uint id1, uint id2)
{
    void *ptr = g_soundeventman.Alloc(52, 8);
    ERSoundEvent *res = new(ptr) ERSoundEvent;
    *(uint *)((char *)res + 8) = id2;
    res->Load(file);
    return res;
}
