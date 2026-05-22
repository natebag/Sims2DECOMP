// 0x8025042C OSLinkFixed (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 0,0x1c(3); cmplwi 0,3; bgt 0f; bge 1f; 0:; li 3,0; b 2f; 1:; li 5,1; bl _s8025042C_0; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025042C_0();
extern "C" void f_8025042C() {}
