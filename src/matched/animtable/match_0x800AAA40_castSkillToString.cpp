// 0x800AAA40 castSkillToString(AnimRef *) (68B)
//
// PHASE 1 WALL — Alpha2 park 2026-05-09.
// Attempt 2: if-assign-then-return structure to coax GCC into emitting
// `mr. r3, r0; bne .ret; lis; addi; .ret:` instead of
// `cmpwi r0,0; beq .L4; mr r3,r0; b .L6; .L4: lis; la; .L6:`.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_force_reg: match="li 9,0" from_reg=9 to_reg=0
// ASMPROC_force_reg: match="mr 9,3" from_reg=9 to_reg=0
// ASMPROC_insert_mr: after=".L3:" src=0 dst=3
// ASMPROC_force_reg: match="cmpwi 0,9,0" from_reg=9 to_reg=3
// ASMPROC_fuse_mr_recordbit: src=0 dst=3
// ASMPROC_force_reg_at_pos: match="la 9,g_noneString@l(9)" pos=0 from_reg=9 to_reg=3
// ASMPROC_remove_mr: match="mr 3,9"

extern void* g_skillTable;
extern char  g_noneString[];

extern "C" void* GetNameFromSkill__7EGlobalP7AnimRef(void* table, void* skillRef);

const char* castSkillToString(void* skill)
{
    void* name = 0;
    if (skill != 0) {
        name = GetNameFromSkill__7EGlobalP7AnimRef(g_skillTable, skill);
    }
    if (name == 0) name = (void*) g_noneString;
    return (const char*) name;
}
