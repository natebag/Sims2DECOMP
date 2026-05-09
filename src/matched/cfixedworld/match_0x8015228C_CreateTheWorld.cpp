// 0x8015228C (52B) CreateTheWorld(void)
// Allocates 68B world via __builtin_new, ctors with (39, 39), stashes in SDA global.

class cFixedWorldImpl {
public:
    char _pad[68];
    cFixedWorldImpl(int x, int y);
};

extern cFixedWorldImpl* g_pTheWorld;  // SDA @ -21488

void CreateTheWorld()
{
    g_pTheWorld = new cFixedWorldImpl(39, 39);
}
