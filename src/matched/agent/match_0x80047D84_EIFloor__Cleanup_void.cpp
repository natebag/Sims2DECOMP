// 0x80047D84 EIFloor::Cleanup(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x0(30); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x0(30); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,30,3; mtspr 8,0; blrl; mr 4,30; bl _s80047D84_0; 0:; lwz 3,0x104(30); cmpwi 3,0; beq 3f; 1:; lwz 31,0x0(3); cmpwi 3,0; beq 2f; li 4,3; bl _s80047D84_1; 2:; mr. 3,31; bne 1b; 3:; li 0,0; stw 0,0x10c(30); stw 0,0x104(30); stw 0,0x108(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80047D84_0();
extern "C" void _s80047D84_1();
extern "C" void f_80047D84() {}
