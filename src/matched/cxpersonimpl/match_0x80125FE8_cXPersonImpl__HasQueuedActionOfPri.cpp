// cXPersonImpl::HasQueuedActionOfPri(int) - 0x80125FE8 (132B)
// ASMPROC_replace_insn: match="lwz 7,680(3)" replacement="lwz 9,680(3)"
// ASMPROC_replace_insn: match="subf 8,7,0" replacement="subf 0,9,0"
// ASMPROC_replace_insn: match="cmplw 0,11,8" replacement="cmplw 0,11,0" occurrence=0
// ASMPROC_insert_mr: after="lis 10,0xcccc" src=9 dst=7
// ASMPROC_insert_mr: after="mr 7,9" src=0 dst=8

class Interaction {
public:
    char m_data[40];
    int m_priority;
    char m_rest[24];
};

struct ActionStorage {
    Interaction actions[10];
    unsigned int startIndex;
    unsigned int endIndex;
};

struct cXPerson_HasQueuedActionOfPri {
    char pad0[0x130];
    ActionStorage m_ring;
    char pad1[0x154];
    int m_pendingFlag;

    bool HasQueuedActionOfPri(int priority);
};

bool cXPerson_HasQueuedActionOfPri::HasQueuedActionOfPri(int priority) {
    int pending = 0;
    if (m_pendingFlag != 0) pending = 1;
    ActionStorage* stor = &m_ring;
    unsigned int startIdx = stor->startIndex;
    unsigned int count = stor->endIndex - startIdx;
    for (unsigned int i = pending; i < count; i++) {
        Interaction* action = &stor->actions[(startIdx + i) % 10];
        if (action->m_priority == priority)
            return 1;
    }
    return 0;
}
