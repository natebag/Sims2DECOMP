// 0x8030F9FC EREdithTreeSet::GetTreeIDByName(char (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 29,0; lwz 0,0x18(31); mr 28,4; cmplw 29,0; bge 2f; li 30,0; 0:; lwz 9,0x1c(31); mr 4,28; add 9,30,9; lwz 3,0x4(9); bl _s8030F9FC_0; cmpwi 3,0; bne 1f; lwz 9,0x1c(31); lwzx 3,30,9; b 3f; 1:; lwz 0,0x18(31); addi 29,29,1; addi 30,30,12; cmplw 29,0; blt 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8030F9FC_0();
extern "C" void f_8030F9FC() {}
