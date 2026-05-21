// 0x801E9410 GetVar_EYE_connectionStatus::Handler(char*) (112B)

extern int Sprintf(char* buf, char* fmt, ...);
extern char s_locked[];      // 0x803F8798
extern char s_unlocked[];    // 0x803F879C
extern char s_fmt[];         // 0x803F87A4

class EyeToyClient {
public:
    char pad_000[176];
    int  m_connState;        // 176
    static int IsSessionEyeToyDisconnected();
};

extern EyeToyClient* g_eyeToy;  // SDA -28712

class GetVar_EYE_connectionStatus {
public:
    int Handler(char* dst);
};

int GetVar_EYE_connectionStatus::Handler(char* dst) {
    int isDisc = EyeToyClient::IsSessionEyeToyDisconnected();
    g_eyeToy->m_connState = isDisc;
    char* str;
    if (isDisc != 0) {
        str = s_locked;
    } else {
        str = s_unlocked;
    }
    int rc = Sprintf(dst, s_fmt, str);
    g_eyeToy->m_connState = 0;
    return rc;
}
