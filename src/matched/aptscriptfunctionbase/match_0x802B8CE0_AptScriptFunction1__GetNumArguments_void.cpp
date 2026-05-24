// 0x802B8CE0 AptScriptFunction1::GetNumArguments(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x34(r3); lwz r3,0x4(r9); blr

struct AptScriptFunctionData {
    void* m_name;        // 0x00
    int m_numArguments;  // 0x04
    int m_unknown8;      // 0x08
    int m_byteCodeSize;  // 0x0C
};

struct AptScriptFunction1 {
    char _pad[0x34];
    AptScriptFunctionData* m_data;

    int GetNumArguments();
};

int AptScriptFunction1::GetNumArguments() {
    return m_data->m_numArguments;
}
