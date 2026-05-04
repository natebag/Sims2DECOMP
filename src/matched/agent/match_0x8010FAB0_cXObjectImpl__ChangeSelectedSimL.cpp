// 0x8010FAB0 (96B) — cXObjectImpl::ChangeSelectedSimL(int) [static]
//
// Static class method. Calls EGlobal::ReverseSelectedPerson(sim_id) on the
// non-SDA singleton at 0x80475DCC, then dispatches to ESimsCam::CenterOnSelectedSim
// via a pointer slot in the parallel array at (0x80475B84 + 0x100 + sim_id*16).
//
// Non-SDA addresses via extern char[N] (size>8 forces ADDR16_HA/LO over EMB_SDA21).
// Volatile cast on the slot pointer defeats CSE — DOL emits both the null-check
// load (→ r0) and the call-arg load (→ r3) rather than reusing one register.
//
// asm_processor: cc1plus reuses r30 (sim_id*16 holder) as the add destination
// and the lwz base — DOL allocates a fresh r11 for both, then `mr r9, r11` to
// move the base into r9 for the second lwz. 4 directives:
//   1. force_reg_at_pos pins the add destination to r11 (rt-only edit, leaves
//      r30/r9 sources untouched).
//   2. force_reg renames r30 → r11 in the first lwz so it threads through r11.
//   3. insert_mr injects `mr 9, 11` between the beq and the second lwz.
//   4. force_reg renames r30 → r9 in the second lwz (post-insertion line).
//
// ASMPROC_force_reg_at_pos: match="add 30,30,9" pos=0 from_reg=30 to_reg=11
// ASMPROC_force_reg: match="lwz 0,256(30)" from_reg=30 to_reg=11
// ASMPROC_insert_mr: after="# beq  cr0" src=11 dst=9
// ASMPROC_force_reg: match="lwz 3,256(30)" from_reg=30 to_reg=9

class EGlobal {
public:
    void ReverseSelectedPerson(int sim_id);
};

class ESimsCam {
public:
    void CenterOnSelectedSim();
};

extern char g_EGlobal[16];
extern char g_simSlotArray[16384];

class cXObjectImpl {
public:
    static void ChangeSelectedSimL(int sim_id);
};

void cXObjectImpl::ChangeSelectedSimL(int sim_id) {
    ((EGlobal*)g_EGlobal)->ReverseSelectedPerson(sim_id);
    char* base = (char*)g_simSlotArray + sim_id * 16;
    ESimsCam* volatile* pp_slot = (ESimsCam* volatile*)(base + 0x100);
    if (*pp_slot != 0) {
        (*pp_slot)->CenterOnSelectedSim();
    }
}
