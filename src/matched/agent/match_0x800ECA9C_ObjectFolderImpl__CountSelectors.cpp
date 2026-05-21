// 0x800eca9c ObjectFolderImpl::CountSelectors(void) const (72B)
// DOL: outer loop idx 0..255 over SelectorNode* array at this+64
//      inner loop: follow m_next chain at +164, count each node including head
//      addi r0,r11,1 computed before lwzx (scheduling artifact)
// SN ProDG: r11=idx, r9=temp/node(reused), r0=next_idx, r10=count
// GCC:      r9=idx, r0=temp,              r10=next_idx, r11=count
// r9 plays dual role (idx before lwzx, node ptr after) — needs regional relabels.
// SN emits 3-operand cmpwi (cmpwi 0,rA,SIMM) so global swap involving r0 corrupts cr0.
// ASMPROC_region_gpr_relabel: start_anchor="li 9,0" start_mode=after end_anchor="lwzx 9,8,0" end_mode=before rename="9:11"
// ASMPROC_force_reg_at_pos: match="li 9,0" pos=0 from_reg=9 to_reg=11
// ASMPROC_force_reg_at_pos: match="slwi 0, 11, 2" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="addi 10, 11, 1" pos=0 from_reg=10 to_reg=0
// ASMPROC_force_reg_at_pos: match="lwzx 9,8,0" pos=2 from_reg=0 to_reg=9
// ASMPROC_region_gpr_relabel: start_anchor="lwzx 9,8,9" start_mode=after end_anchor="mr 9,10" end_mode=before rename="11:10" unsafe_clobber=true
// ASMPROC_force_reg_at_pos: match="mr 9,10" pos=0 from_reg=9 to_reg=11
// ASMPROC_force_reg_at_pos: match="mr 11,10" pos=1 from_reg=10 to_reg=0
// ASMPROC_force_reg_at_pos: match="add 3,3,11" pos=2 from_reg=11 to_reg=10
// ASMPROC_force_reg_at_pos: match="cmpwi 0,9,255" pos=1 from_reg=9 to_reg=11

struct SelectorNode {
    char _pad[164];
    SelectorNode* m_next;  // +164
};

struct ObjectFolderImpl {
    char _pad[64];
    SelectorNode* m_selectors[256];  // +64
    int CountSelectors() const;
};

int ObjectFolderImpl::CountSelectors() const {
    int total = 0;
    for (int i = 0; i < 256; i++) {
        SelectorNode* node = m_selectors[i];
        int count = 0;
        if (node) {
            do {
                node = node->m_next;
                count++;
            } while (node);
        }
        total += count;
    }
    return total;
}
