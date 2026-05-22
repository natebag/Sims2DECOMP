// 0x80319F08 ERModel::RegisterMorphTarget(ERModel (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 27,5; mr 29,3; mr 28,4; cmplwi 27,12; bgt 0f; addi 9,29,60; lwz 11,0x40(28); lwz 0,0x4(9); mr 26,9; cmpw 0,11; beq 1f; 0:; li 3,0; b 5f; 1:; rlwinm 9,27,2,0,29; addi 11,29,156; lwzx 0,11,9; mr 25,9; cmpwi 0,0; bne 4f; stwx 28,11,25; li 30,0; addi 24,29,204; lwz 0,0x4(26); cmpw 30,0; bge 3f; li 31,0; 2:; lwz 3,0x3c(29); mr 5,27; lwz 4,0x3c(28); addi 30,30,1; add 3,3,31; add 4,4,31; bl _s80319F08_0; addi 31,31,24; lwz 0,0x4(26); cmpw 30,0; blt 2b; 3:; lis 9,-32702; lfs f0,0x8d8(9); stfsx f0,24,25; 4:; li 3,1; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80319F08_0();
extern "C" void f_80319F08() {}
