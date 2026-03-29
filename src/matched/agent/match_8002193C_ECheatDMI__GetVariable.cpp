/* ECheatDMI::GetVariable(void) at 0x8002193C (12B) */

struct ECheatDMI {
    char pad[12];
    int* m_pLookup;
    int GetVariable();
};

int ECheatDMI::GetVariable() {
    return *(int*)((char*)m_pLookup + 0x50);
}
