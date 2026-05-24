// 0x800eca9c ObjectFolderImpl::CountSelectors(void) const (72B)
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

struct ObjectFolderImpl {
    void CountSelectors();
};

void ObjectFolderImpl::CountSelectors() {
}
