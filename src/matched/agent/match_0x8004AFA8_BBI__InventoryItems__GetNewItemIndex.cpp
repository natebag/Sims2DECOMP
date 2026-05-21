// ASMPROC_replace_insn: match="li 9,0" replacement="li 11,0"
// ASMPROC_replace_insn: match="li 11,-1" replacement="li 10,-1"
// ASMPROC_replace_insn: match="lwzx 0,3,9" replacement="lwzx 0,3,11"
// ASMPROC_replace_insn: match="li 11,0" replacement="li 10,0" occurrence=1
// ASMPROC_replace_insn: match="addi 9,9,1" replacement="addi 11,11,1"
// ASMPROC_replace_insn: match="cmpwi 0,9,35" replacement="cmpwi 0,11,35"
// ASMPROC_replace_insn: match="lwzu 0,4(3)" replacement="slwi 0,11,2"
// ASMPROC_inject_before: before="cmpwi 0,0,0" lines="lwzx 9,3,0" occurrence=1
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,9,0" occurrence=1
// ASMPROC_replace_insn: match="mr 11,9" replacement="mr 10,11"
// ASMPROC_replace_insn: match="mr 3,11" replacement="mr 3,10"
// 0x8004AFA8 (68B) BBI::InventoryItems::GetNewItemIndex()

struct InventoryItem {};

struct BBI_InventoryItems {
    InventoryItem* m_items[36];
    int GetNewItemIndex() const;
};

int BBI_InventoryItems::GetNewItemIndex() const {
    int i = 0;
    int result = -1;
    if (m_items[i] == 0) {
        result = i;
    } else {
        while (++i <= 35) {
            if (m_items[i] == 0) {
                result = i;
                break;
            }
        }
    }
    return result;
}
