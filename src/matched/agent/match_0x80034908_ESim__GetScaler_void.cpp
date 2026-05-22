// 0x80034908 ESim::GetScaler(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x63c(3); addi 9,9,104; lwz 11,0x8(9); cmpwi 11,0; beq 0f; lwz 9,0x120(11); lfs f1,0x88(9); blr; 0:; lwz 9,0xc(9); cmpwi 9,0; bne 1f; lis 9,-32707; lfs f1,0x120c(9); blr; 1:; lwz 9,0x120(9); lfs f1,0x88(9)"
extern "C" float f_80034908() {}
