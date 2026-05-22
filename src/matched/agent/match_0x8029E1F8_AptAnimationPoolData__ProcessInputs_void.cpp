// 0x8029E1F8 AptAnimationPoolData::ProcessInputs(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 0,0x34(31); cmpw 30,0; bge 1f; li 29,0; 0:; lwz 9,0x38(31); subfic 0,30,0; adde 5,0,30; mr 3,31; addi 30,30,1; lwzx 4,29,9; addi 29,29,4; bl _s8029E1F8_0; lwz 0,0x34(31); cmpw 30,0; blt 0b; 1:; li 0,0; stw 0,0x34(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8029E1F8_0();
extern "C" void f_8029E1F8() {}
