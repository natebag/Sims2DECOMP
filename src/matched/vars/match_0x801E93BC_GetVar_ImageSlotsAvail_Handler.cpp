// 0x801E93BC GetVar_ImageSlotsAvail::Handler(char*) (84B)

extern int Sprintf(char* buf, char* fmt, ...);
extern char s_locked[];      // 0x803F8798
extern char s_unlocked[];    // 0x803F879C
extern char s_imgSlotFmt[];  // 0x803F87A4

class EyeToyClient {
public:
    char pad_000[132];
    int  m_imgFlag;
};

extern EyeToyClient* g_eyeToy;  // SDA -28712

class GetVar_ImageSlotsAvail {
public:
    int Handler(char* dst);
};

int GetVar_ImageSlotsAvail::Handler(char* dst) {
    char* str;
    if (g_eyeToy->m_imgFlag != 0) {
        str = s_unlocked;
    } else {
        str = s_locked;
    }
    return Sprintf(dst, s_imgSlotFmt, str);
}
