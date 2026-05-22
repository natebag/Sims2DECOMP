// 0x800CC4E4 Neighbor::ResetAllWantsAndFears(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 30,0; li 31,0; 0:; lwz 3,0x194(29); addi 30,30,1; add 3,3,31; bl _s800CC4E4_0; addi 31,31,12; cmplwi 30,19; ble 0b; li 11,7; li 0,0; mtspr 9,11; addi 9,29,408; 1:; stw 0,0x0(9); addi 9,9,4; bdnz 1b; li 0,0; stw 0,0x1b4(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800CC4E4_0();
extern "C" void f_800CC4E4() {}
