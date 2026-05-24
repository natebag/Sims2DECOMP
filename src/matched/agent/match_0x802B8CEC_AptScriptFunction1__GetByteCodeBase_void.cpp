// FLAGS: -fno-schedule-insns
// 0x802B8CEC AptScriptFunction1::GetByteCodeBase(void) (12B)
// lwz r3,0x34(r3); addi r3,r3,24; blr
struct AptScriptFunction1 {
    char pad[0x34];
    char* m_codeBase;  // offset 0x34
    char* GetByteCodeBase() const;
};
char* AptScriptFunction1::GetByteCodeBase() const {
    return m_codeBase + 24;
}
