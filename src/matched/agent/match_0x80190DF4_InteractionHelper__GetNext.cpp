// InteractionHelper::GetNext(IHRecord *) @ 0x80190DF4 (24B)
// ASMPROC_nop_before: match="cmpwi 0,3,0"
// ASMPROC_replace_insn: match="nop" replacement="mr 3,0"
// ASMPROC_replace_insn: match="lwz 3,4(4)" replacement="lwz 0,4(4)"
// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="cmpwi 0,0,0"

struct IHRecord {
    void* _pad0;
    IHRecord* m_next;
    void* _pad8;
    IHRecord* m_alt;
};

struct InteractionHelper {
    IHRecord* GetNext(IHRecord* rec);
};

IHRecord* InteractionHelper::GetNext(IHRecord* rec) {
    IHRecord* n = rec->m_next;
    if (n) return n;
    return rec->m_alt;
}
