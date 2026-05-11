// 0x800D53E4 NghResFile::GetThumbIdFromFamilyAndIndex(int family, int index) (56B)
//
// PHASE 1 WALL — Alpha2 park 2026-05-08.
// 3-case lookup. Non-static member; `this` (r3 on entry) is clobbered with
// family via initial `mr r3, r4`, so the body operates on family-via-r3 for
// the first branch and family-via-r4 for the second branch.
//
// GCC baseline (52B equivalent — same 14 insns as DOL) is byte-for-byte
// aligned except in the .L3 tail where GCC CSEs family into r3 throughout
// and uses r3 directly for the slwi/add chain. DOL keeps family in r4
// post-mr and routes the multiply through r0:
//
//   DOL                            GCC current
//   cmpwi r4, 4                  cmpwi 0,3,4
//   blelr                        bclr 4,1
//   addi  r3, r4, -20            addi 3,3,-20
//   slwi  r0, r3, 2              slwi 3,3,2     (dest r3 not r0)
//   add   r3, r0, r5             add  3,3,5     (src r3 not r0)
//   addi  r3, r3, 5              addi 3,3,5
//   blr                          blr
//
// Recipe:
//   1) force_reg cmpwi 0,3,4 → cmpwi 0,4,4 (whole-line r3→r4 OK; imm 4 unaffected)
//   2) force_reg_at_pos addi 3,3,-20 pos=1 r3→r4 (source only; dest stays r3)
//   3) force_reg_at_pos slwi 3,3,2 pos=0 r3→r0 (dest to r0)
//   4) force_reg_at_pos add 3,3,5 pos=1 r3→r0 (source to r0; r5 imm stays)
//
// Branch-hint bit (blelr 0x4c81 vs 0x4d81) — observed-only after recipe; if it's
// the residual, propose replace_insn directive to MainGuy.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_force_reg: match="cmpwi 0,3,4" from_reg=3 to_reg=4
// ASMPROC_force_reg_at_pos: match="addi 3,3,-20" pos=1 from_reg=3 to_reg=4
// ASMPROC_force_reg_at_pos: match="slwi 3,3,2" pos=0 from_reg=3 to_reg=0
// ASMPROC_force_reg_at_pos: match="add 3,3,5" pos=1 from_reg=3 to_reg=0

class NghResFile {
public:
    int GetThumbIdFromFamilyAndIndex(int family, int index);
};

int NghResFile::GetThumbIdFromFamilyAndIndex(int family, int index)
{
    int f = family;
    if (f == 1 && index == 1) return 3;
    if (family <= 4) return f;
    return ((family - 20) * 4) + index + 5;
}
