// 0x8035FCE8 ERTQuantize4D::Reduction(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x1024(31); lwz 0,0x1014(31); cmplw 9,0; ble 3f; li 0,1; li 29,-1; stw 0,0x102c(31); li 30,0; 0:; lwz 0,0x102c(31); lhz 9,0x1004(31); stw 0,0x1028(31); stw 29,0x102c(31); cmpwi 9,0; stw 30,0x1024(31); beq 1f; mulli 9,9,72; lwz 0,0x1008(31); add 4,0,9; b 2f; 1:; li 4,0; 2:; mr 3,31; bl _s8035FCE8_0; lwz 9,0x1024(31); lwz 0,0x1014(31); cmplw 9,0; bgt 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8035FCE8_0();
extern "C" void f_8035FCE8() {}
