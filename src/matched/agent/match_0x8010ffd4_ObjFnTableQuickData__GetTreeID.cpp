// 0x8010ffd4 (68B) ObjFnTableQuickData::GetTreeID(ObjEntryPoint)
// ASMPROC_replace_insn: match="li 9,0" replacement="li 0,0"
// ASMPROC_replace_insn: match="lwz 0,12(3)" replacement="lwz 9,12(3)"
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,9,0"
// ASMPROC_replace_insn: match="add 9,4,4" replacement="add 0,4,4"
// ASMPROC_replace_insn: match="add 9,9,0" replacement="addi 9,9,4"
// ASMPROC_replace_insn: match="add 9,4,4" replacement="add 0,4,4"
// ASMPROC_replace_insn: match="add 9,9,3" replacement="addi 9,3,4"
// ASMPROC_replace_insn: match="lha 9,4(9)" replacement="lhax 0,9,0"
// ASMPROC_replace_insn: match="mr 3,9" replacement="mr 3,0"

typedef int ObjEntryPoint;

class ObjFnTableQuickData {
public:
    char pad[12];
    short* m_table;
    short* m_backup;
    int GetTreeID(ObjEntryPoint ep) const;
};

int ObjFnTableQuickData::GetTreeID(ObjEntryPoint ep) const {
    int result = 0;
    if ((unsigned int)ep <= 29u) {
        short* table = m_table;
        if (table) {
            result = table[ep + 2];
        } else {
            short* backup = m_backup;
            if (backup) { result = backup[ep + 2]; }
        }
    }
    return result;
}
