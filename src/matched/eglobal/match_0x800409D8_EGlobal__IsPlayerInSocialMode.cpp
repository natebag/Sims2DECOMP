// 0x800409D8 (72B) EGlobal::IsPlayerInSocialMode(int)
// Tech #47 MI-vcall via double-indirect secondary vtable @ offset +4

extern "C" void* GetCurrentSim__7EGlobalFi(int player);

class EGlobal {
public:
    static int IsPlayerInSocialMode(int player);
};

int EGlobal::IsPlayerInSocialMode(int player) {
    void* sim = GetCurrentSim__7EGlobalFi(player);
    if (sim == 0) return 0;
    char* obj = (char*)sim;
    char* vt = *(char**)(obj + 4);
    short adj = *(short*)(vt + 816);
    void* fn = *(void**)(vt + 820);
    return ((int (*)(void*))fn)(obj + adj);
}
