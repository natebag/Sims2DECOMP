// 0x8026C804 EAStringC::operator==(EAStringC (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x0(3); lwz 4,0x0(4); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 0f; li 3,0; b 2f; 0:; cmpw 3,4; beq 1f; addi 3,3,8; addi 4,4,8; bl _s8026C804_0; subfic 0,3,0; adde 3,0,3; b 2f; 1:; li 3,1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026C804_0();
extern "C" void f_8026C804() {}
