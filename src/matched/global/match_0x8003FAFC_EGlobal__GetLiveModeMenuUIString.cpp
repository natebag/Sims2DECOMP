// 0x8003FAFC EGlobal::GetLiveModeMenuUIString (16b)

extern char g_liveModeMenuUIString[4];

class EGlobal {
public:
    static char* GetLiveModeMenuUIString(char* out);
};

char* EGlobal::GetLiveModeMenuUIString(char* out) {
    char* dst = out;
    *(char**)dst = *(char**)g_liveModeMenuUIString;
    return out;
}
