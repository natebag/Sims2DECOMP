// 0x802B8CF8 AptScriptFunction1::GetByteCodeSize(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x34(r3); lwz r3,0xc(r9); blr

struct AptScriptFunctionData {
    void* m_name;        // 0x00
    int m_numArguments;  // 0x04
    int m_unknown8;      // 0x08
    int m_byteCodeSize;  // 0x0C
};

struct AptScriptFunction1 {
    char _pad[0x34];
    AptScriptFunctionData* m_data;

    int GetByteCodeSize();
};

int AptScriptFunction1::GetByteCodeSize() {
    return m_data->m_byteCodeSize;
}
