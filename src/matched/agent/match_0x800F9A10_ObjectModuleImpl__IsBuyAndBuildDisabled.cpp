// FLAGS: -fno-schedule-insns
// 0x800F9A10 (36B) ObjectModuleImpl::IsBuyAndBuildDisabled(void)
// DOL: lwz r9,0x2034(r3) | li r11,1 | lwz r0,0x2038(r3) | subf r0,r9,r0
//      rlwinm. r9,r0,30,2,31 | bne +8 | li r11,0 | mr r3,r11 | blr

struct ObjMod {
    char pad[0x2034];
    unsigned int m_flags;
    unsigned int m_limit;
    int IsBuyAndBuildDisabled();
};

int ObjMod::IsBuyAndBuildDisabled() {
    unsigned int flags = m_flags;
    int result = 1;
    unsigned int limit = m_limit;
    if (((limit - flags) >> 2) == 0) result = 0;
    return result;
}
