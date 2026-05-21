// 0x800AB968 Behavior::GetResFileID(short) (76B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="lwz 3,g_globalFile@sda21(0)" replacement="lwz 3,-31848(13)"
// ASMPROC_inject_before: before="li 3,-1" lines=".Lfail:" occurrence=0
// ASMPROC_replace_insn: match="bc 12,1,.L6" replacement="bc 12,1,.Lfail"
// PARK: 1 byte-diff at offset 0x3C — DOL bgt backwards to shared early-return,
// COMPILED bgt forward to shared late-return. MutatorSmith candidate (branch-direction
// canonicalization). Source semantics correct.

class SomeObj {
public:
    int unused;
    int m_f4;
    int m_f8;
};

extern int g_globalFile;  // SDA -31848

class Behavior {
public:
    void* pad0;
    SomeObj* m_obj;
    int GetResFileID(short id);
};

int Behavior::GetResFileID(short id) {
    if ((unsigned int)(id - 256) > 8744u) return -1;
    if (id <= 4095) return g_globalFile;
    if (id <= 8191) return m_obj->m_f4;
    if (id > 9000) return -1;
    return m_obj->m_f8;
}
