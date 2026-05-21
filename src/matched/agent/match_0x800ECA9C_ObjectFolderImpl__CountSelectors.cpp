// 0x800ECA9C (72B) ObjectFolderImpl::CountSelectors()
// ASMPROC_replace_insn: match="li 9,0" replacement="li 11,0"
// ASMPROC_replace_insn: match="slwi 0,9,2" replacement="slwi 9,11,2"
// ASMPROC_replace_insn: match="addi 10,9,1" replacement="addi 0,11,1"
// ASMPROC_replace_insn: match="lwzx 9,8,0" replacement="lwzx 9,8,9"
// ASMPROC_replace_insn: match="li 11,0" replacement="li 10,0" occurrence=1
// ASMPROC_replace_insn: match="addi 11,11,1" replacement="addi 10,10,1"
// ASMPROC_replace_insn: match="mr 9,10" replacement="mr 11,0"
// ASMPROC_replace_insn: match="add 3,3,11" replacement="add 3,3,10"
// ASMPROC_replace_insn: match="cmpwi 0,9,255" replacement="cmpwi 0,11,255"

struct Selector {
    char pad[164];
    Selector* m_next;
};

class ObjectFolderImpl {
public:
    char pad[64];
    Selector* m_table[256];
    int CountSelectors();
};

int ObjectFolderImpl::CountSelectors() {
    int total = 0;
    for (int i = 0; i <= 255; i++) {
        Selector* sel = m_table[i];
        int count = 0;
        if (sel) {
            do {
                sel = sel->m_next;
                count++;
            } while (sel);
        }
        total += count;
    }
    return total;
}
