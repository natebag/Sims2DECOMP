// cXPersonImpl::GetNextQueueStr(int) - 0x8011AD9C (104B)
// ASMPROC_replace_insn: match="addi 10,3,304" replacement="addi 11,3,304"
// ASMPROC_replace_insn: match="lwz 11,680(10)" replacement="lwz 3,680(11)"
// ASMPROC_replace_insn: match="add 11,11,9" replacement="add 3,3,9"
// ASMPROC_replace_insn: match="mulhwu 0,11,0" replacement="mulhwu 0,3,0"
// ASMPROC_replace_insn: match="mulli 9,0,10" replacement="mulli 0,0,10"
// ASMPROC_replace_insn: match="subf 0,9,11" replacement="subf 3,0,3"
// ASMPROC_replace_insn: match="mulli 3,0,68" replacement="mulli 3,3,68"
// ASMPROC_replace_insn: match="add 3,10,3" replacement="add 3,11,3"

class BString2 {
public:
    const char* c_str() const;
};

class Interaction {
public:
    char m_data[68];
    BString2& GetName() const;
};

struct ActionStorage {
    Interaction actions[10];
    unsigned int startIndex;
};

struct cXPerson_GetNextQueueStr {
    char pad0[0x130];
    ActionStorage m_ring;
    char pad1[0x158];
    int m_pendingFlag;

    const char* GetNextQueueStr(int n);
};

const char* cXPerson_GetNextQueueStr::GetNextQueueStr(int n) {
    int pending = 0;
    if (m_pendingFlag != 0)
        pending = 1;
    ActionStorage* stor = &m_ring;
    int offset = n + pending;
    unsigned int idx = (stor->startIndex + offset) % 10;
    return stor->actions[idx].GetName().c_str();
}
