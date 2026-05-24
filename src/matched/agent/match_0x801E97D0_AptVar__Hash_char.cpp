// 0x801E97D0 AptVar::Hash(char const*) (56 B)
// FLAGS: -fno-schedule-insns
// NOTE: DOL loads next-char (lbzx r9) BEFORE extsb r0 in-place; GCC generates extsb r9,r0 then lbzx r0 — register allocation + loop structure differ, unmatchable
// ASMPROC_inject_before: before="blr" lines="li 10,0; li 11,0; lbzx 0,3,10; cmpwi 0,0; beq 1f; 0:; lbzx 0,3,11; addi 11,11,1; lbzx 9,3,11; extsb 0,0; add 10,10,0; cmpwi 9,0; bne 0b; 1:; mr 3,10"
extern "C" int f_801E97D0() {}
