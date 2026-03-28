/* EController::GetBtnResultAny(unsigned int, bool, unsigned int) */
/* at 0x8030503C (64 bytes) */

struct SomeData {
    char _pad[0x78];
    int m_exclusiveFlag;
};

struct EController {
    char _pad[0x200];
    SomeData* m_pData;

    int GetBtnResultAny(unsigned int btn, bool shortcut, unsigned int mask);
};

int EController::GetBtnResultAny(unsigned int btn, bool shortcut, unsigned int mask) {
    if (btn & mask) {
        if (shortcut == 0)
            return 1;
        SomeData* p = m_pData;
        if (p->m_exclusiveFlag == 0) {
            p->m_exclusiveFlag = 1;
            return 1;
        }
    }
    return 0;
}
