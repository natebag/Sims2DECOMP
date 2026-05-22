// 0x80034AB8 ESim::GetPlayerIndex(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 11,0x3d0(3); addi 9,9,24012; li 3,-1; lwz 0,0xbc(9); cmpw 11,0; bne 0f; li 3,0; blr; 0:; lwz 0,0xc0(9); cmpw 11,0; bnelr; li 3,1"
extern "C" int f_80034AB8() {}
