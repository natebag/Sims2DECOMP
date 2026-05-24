// 0x802B8CD4 AptScriptFunction1::GetName(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x34(r3); lwz r3,0x0(r9); blr

struct AptScriptFunctionData {
    void* m_name;        // 0x00
    int m_numArguments;  // 0x04
    int m_unknown8;      // 0x08
    int m_byteCodeSize;  // 0x0C
};

struct AptScriptFunction1 {
    char _pad[0x34];
    AptScriptFunctionData* m_data;

    void* GetName();
};

void* AptScriptFunction1::GetName() {
    return m_data->m_name;
}
