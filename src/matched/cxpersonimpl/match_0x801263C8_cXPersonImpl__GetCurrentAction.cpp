// cXPersonImpl::GetCurrentAction - 0x801263C8 (68B)
// ASMPROC_replace_insn: match="addi 10,3,304" replacement="addi 9,3,304"
// ASMPROC_replace_insn: match="lwz 11,680(10)" replacement="lwz 11,680(9)"
// ASMPROC_replace_insn: match="mulli 9,0,10" replacement="mulli 0,0,10"
// ASMPROC_replace_insn: match="subf 0,9,11" replacement="subf 11,0,11"
// ASMPROC_replace_insn: match="mulli 3,0,68" replacement="mulli 11,11,68"
// ASMPROC_replace_insn: match="add 3,10,3" replacement="add 3,9,11"
// ASMPROC_replace_insn: match="lis 3,s_emptyCurrentInteraction@ha" replacement="lis 9,s_emptyCurrentInteraction@ha"
// ASMPROC_replace_insn: match="la 3,s_emptyCurrentInteraction@l(3)" replacement="la 3,s_emptyCurrentInteraction@l(9)"

struct Interaction { char data[0x44]; };

struct ActionStorage {
    Interaction actions[10];
    unsigned int startIndex;
};

struct cXPerson_GetCurrentAction {
    char pad0[0x130];
    ActionStorage m_ring;
    char pad1[0x158];
    int m_pendingFlag;

    Interaction* GetCurrentAction();
};

extern Interaction s_emptyCurrentInteraction;

Interaction* cXPerson_GetCurrentAction::GetCurrentAction() {
    if (m_pendingFlag == 0)
        return &s_emptyCurrentInteraction;
    ActionStorage* stor = &m_ring;
    unsigned int idx = stor->startIndex % 10;
    return stor->actions + idx;
}
