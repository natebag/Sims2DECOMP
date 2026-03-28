/* ECheatDMI::GetDescription(char *, int) at 0x80021498 (72B) */

char* strncpy(char*, const char*, int);

struct ECheatLookup {
    char pad_00[0x08];
    char m_name[64];
};

struct ECheatDMI {
    char pad_00[0x0C];
    ECheatLookup* m_cheat;

    void GetDescription(char*, int);
};

void ECheatDMI::GetDescription(char* dest, int maxLen) {
    strncpy(dest, m_cheat->m_name, maxLen);
    dest[maxLen - 1] = 0;
}
