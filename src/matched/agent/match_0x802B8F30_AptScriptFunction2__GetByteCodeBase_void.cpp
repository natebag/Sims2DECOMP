// FLAGS: -fno-schedule-insns
// 0x802B8F30 AptScriptFunction2::GetByteCodeBase(void) (12B)
// lwz r3,0x34(r3); addi r3,r3,28; blr
struct AptScriptFunction2 {
    char pad[0x34];
    char* m_codeBase;  // offset 0x34
    char* GetByteCodeBase() const;
};
char* AptScriptFunction2::GetByteCodeBase() const {
    return m_codeBase + 28;
}
