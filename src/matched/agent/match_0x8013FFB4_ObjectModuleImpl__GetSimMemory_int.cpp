// 0x8013FFB4 ObjectModuleImpl::GetSimMemory(int, (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 3,4; li 0,0; mr 4,5; mr 30,6; addi 5,1,8; stw 0,0xc(1); stw 0,0x8(1); addi 6,1,12; bl _s8013FFB4_0; lwz 11,0x8(1); li 5,2; lwz 4,0xc(1); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; mr 4,30; bl _s8013FFB4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8013FFB4_0();
extern "C" void _s8013FFB4_1();
extern "C" void f_8013FFB4() {}
