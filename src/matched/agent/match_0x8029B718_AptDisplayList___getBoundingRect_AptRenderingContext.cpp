// 0x8029B718 AptDisplayList::_getBoundingRect(AptRenderingContext (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,0x0(3); mr 28,4; mr 29,5; lwz 9,0x0(11); lwz 31,0x54(9); cmpwi 31,0; beq 3f; 0:; lwz 0,0x0(31); andis. 9,0,2048; beq 2f; mr 3,31; li 30,0; bl _s8029B718_0; cmpwi 3,19; bne 1f; mr 3,31; bl _s8029B718_1; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; bne 2f; lwz 9,0x4c(31); lwz 0,0x0(9); cmpwi 0,0; bge 2f; mr 3,31; mr 4,28; mr 5,29; bl _s8029B718_2; 2:; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8029B718_0();
extern "C" void _s8029B718_1();
extern "C" void _s8029B718_2();
extern "C" void f_8029B718() {}
