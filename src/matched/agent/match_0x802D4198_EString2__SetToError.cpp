/* EString2::SetToError(void) at 0x802D4198 (16B) */

extern char g_errorString[];

struct EString2 {
    char* m_str;

    void SetToError(void);
};

void EString2::SetToError(void) {
    m_str = g_errorString;
}
