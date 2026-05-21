// 0x801C85D0 MMUTarget::UpdateDevMenuState(char*, char*) (76B)

extern "C" int AtoI(char* s);

extern char g_devMenuFlag_804761D0[16];

class MMUTarget {
public:
    void ChangeScreenMode(int mode);
    void UpdateDevMenuState(char* name, char* value);
};

void MMUTarget::UpdateDevMenuState(char* name, char* value) {
    if (*(int*)g_devMenuFlag_804761D0 == 0) return;
    ChangeScreenMode(AtoI(value));
}
