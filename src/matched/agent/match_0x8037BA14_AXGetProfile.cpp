// 0x8037BA14 AXGetProfile (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8037BA14_0; lwz 0,-22080(13); cmplwi 0,0; mr 31,0; beq 0f; addi 31,31,-1; 0:; li 0,0; stw 0,-22080(13); bl _s8037BA14_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8037BA14_0();
extern "C" void _s8037BA14_1();
extern "C" void f_8037BA14() {}
