// 0x8028459C AptAnimationPoolData::clearBIL(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 30,0; lwz 0,0x10(31); cmpw 30,0; bge 1f; lis 27,-32704; lis 28,-32704; li 29,0; 0:; lwz 9,0x14(31); addi 4,27,12184; addi 5,28,11876; li 6,1300; lwzx 11,29,9; addi 30,30,1; addi 29,29,28; lwz 9,0x8(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x10(31); cmpw 30,0; blt 0b; 1:; li 0,0; stw 0,0x10(31); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_8028459C() {}
