// 0x802D5A10 ETypeInfo::IsDerivedFrom(ETypeInfo*) (36 B)
// FLAGS: -fno-schedule-insns
//
// Walks parent-pointer chain (at +0x18) looking for `other`. Returns 1 if found,
// 0 if chain ends at NULL.
//
// asm:
//   0: cmpw r3, r4
//      beq 1f
//      lwz r3, 0x18(r3)
//      cmpwi r3, 0
//      bne 0b
//      li r3, 0
//      blr
//   1: li r3, 1
//      blr

struct ETypeInfo {
    char pad[0x18];
    ETypeInfo* m_parent;

    int IsDerivedFrom(ETypeInfo* other);
};

int ETypeInfo::IsDerivedFrom(ETypeInfo* other) {
    ETypeInfo* p = this;
    while (p != other) {
        p = p->m_parent;
        if (p == 0) return 0;
    }
    return 1;
}
