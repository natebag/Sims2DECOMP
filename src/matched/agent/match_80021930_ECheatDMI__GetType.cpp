/* ECheatDMI::GetType(void) at 0x80021930 (12B) */

struct ECheatDMI {
    char pad[12];
    int* m_pLookup;
    int GetType();
};

int ECheatDMI::GetType() {
    return *(int*)((char*)m_pLookup + 0x4C);
}
