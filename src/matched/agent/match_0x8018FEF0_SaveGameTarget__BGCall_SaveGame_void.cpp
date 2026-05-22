// 0x8018FEF0 SaveGameTarget::BGCall_SaveGame(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-22756(13); mr 5,3; lis 4,-32743; li 0,0; lwz 9,0x0(11); addi 4,4,-196; lha 3,0x48(9); lwz 9,0x4c(9); add 3,11,3; stw 0,-21480(13); mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8018FEF0() {}
