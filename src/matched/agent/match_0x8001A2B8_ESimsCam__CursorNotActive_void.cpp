// 0x8001A2B8 ESimsCam::CursorNotActive(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8001A2B8_0; lwz 4,0x4(30); li 5,-1; bl _s8001A2B8_1; mr. 3,3; beq 2f; lwz 0,0x44(3); li 9,0; cmpwi 0,0; bne 0f; lwz 0,0x48(3); cmpwi 0,0; beq 1f; 0:; li 9,1; 1:; cmpwi 9,0; li 3,1; bne 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001A2B8_0();
extern "C" void _s8001A2B8_1();
extern "C" void f_8001A2B8() {}
