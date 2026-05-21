// 0x80110018 (68B) ObjFnTableQuickData::GetCheckTreeID(ObjEntryPoint)
// ASMPROC_replace_insn: match="li 9,0" replacement="li 0,0"
// ASMPROC_replace_insn: match="lwz 0,12(3)" replacement="lwz 9,12(3)"
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,9,0"
// ASMPROC_replace_insn: match="add 9,4,4" replacement="add 0,4,4"
// ASMPROC_replace_insn: match="add 9,9,0" replacement="addi 9,9,64"
// ASMPROC_replace_insn: match="add 9,4,4" replacement="add 0,4,4"
// ASMPROC_replace_insn: match="add 9,9,3" replacement="addi 9,3,64"
// ASMPROC_replace_insn: match="lha 9,64(9)" replacement="lhax 0,9,0"
// ASMPROC_replace_insn: match="mr 3,9" replacement="mr 3,0"

typedef int ObjEntryPoint;

class ObjFnTableQuickData {
public:
    char pad[12];
    short* m_table;
    short* m_backup;
    int GetCheckTreeID(ObjEntryPoint ep) const;
};

int ObjFnTableQuickData::GetCheckTreeID(ObjEntryPoint ep) const {
    int result = 0;
    if ((unsigned int)ep <= 29u) {
        short* table = m_table;
        if (table) {
            result = table[ep + 32];
        } else {
            short* backup = m_backup;
            if (backup) { result = backup[ep + 32]; }
        }
    }
    return result;
}
