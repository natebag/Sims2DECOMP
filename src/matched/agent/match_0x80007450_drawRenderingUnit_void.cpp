// 0x80007450 drawRenderingUnit(void (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 30,0; lwz 0,0x4(29); mr 31,4; cmpw 30,0; bge 6f; li 28,0; 0:; lwz 9,0x8(29); lwzx 3,28,9; lwz 0,0x0(3); cmpwi 0,5; bgt 1f; cmpwi 0,4; bge 3f; cmpwi 0,1; beq 2f; b 5f; 1:; cmpwi 0,6; beq 4f; b 5f; 2:; mr 4,31; bl _s80007450_0; b 5f; 3:; mr 4,31; bl _s80007450_1; b 5f; 4:; mr 4,31; bl _s80007450_2; 5:; lwz 0,0x4(29); addi 30,30,1; addi 28,28,4; cmpw 30,0; blt 0b; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80007450_0();
extern "C" void _s80007450_1();
extern "C" void _s80007450_2();
extern "C" void f_80007450() {}
