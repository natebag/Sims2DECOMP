// 0x800F1264 ObjectFolderImpl::GetTypeAttrBlock(int) (56B)
//
// PHASE 1 WALL — Alpha2 park 2026-05-08.
// Linear search of m_begin/m_end iterator pair returning first attr whose
// first int field equals the query type.
//
// DOL pattern:
//   lwz   r0,  1636(r3)    ; end → r0 (DOL choice)
//   lwz   r9,  1632(r3)
//   cmpw  r9, r0
//   beq   .ret_null
//   mr    r11, r0          ; snapshot end → r11
// .loop:
//   lwz   r3, 0(r9)
//   lwz   r0, 0(r3)
//   cmpw  r0, r4
//   beqlr
//   addi  r9, r9, 4
//   cmpw  r9, r11
//   bne   .loop
// .ret_null:
//   li    r3, 0
//   blr
//
// Goto-form C++ source forces cc1plus to emit the separate `.L_ret_null:` block
// at function end (instead of folding the empty-check into a bclr). Result is
// 13-insn / 52B layout — same shape as DOL but with r11 chosen for end and
// the snapshot mr missing. Three asm directives finish it:
//   1) force_reg: lwz 11→lwz 0 on the initial load
//   2) force_reg: first cmpw 0,9,11 → cmpw 0,9,0 (occurrence 0; loop's cmpw
//      stays untouched at occurrence 1, already pointing at r11)
//   3) insert_mr: after the beq, snapshot r0 → r11 so the loop's cmpw r9,r11
//      reads the right value.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_force_reg: match="lwz 11,1636(3)" from_reg=11 to_reg=0
// ASMPROC_force_reg: match="cmpw 0,9,11" from_reg=11 to_reg=0 occurrence=0
// ASMPROC_insert_mr: after="bc 12,2,.L4" src=0 dst=11

class ObjectFolderImpl {
public:
    char  _0[0x660];
    void** m_begin;
    void** m_end;

    void* GetTypeAttrBlock(int queryType);
};

void* ObjectFolderImpl::GetTypeAttrBlock(int queryType)
{
    void** end = m_end;
    void** it  = m_begin;
    if (it == end) goto ret_null;
    do {
        int* attr = (int*) *it;
        if (*attr == queryType) return attr;
        ++it;
    } while (it != end);
ret_null:
    return 0;
}
