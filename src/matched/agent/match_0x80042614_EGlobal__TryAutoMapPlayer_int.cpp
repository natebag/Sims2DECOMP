// 0x80042614 EGlobal::TryAutoMapPlayer(int) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; lwz 3,-26524(13); bl _s80042614_0; cmpwi 3,0; beq 1f; lwz 3,-26524(13); mr 4,28; bl _s80042614_1; b 6f; 0:; lwz 3,-26524(13); mr 4,28; mr 5,31; bl _s80042614_2; mr 3,31; b 6f; 1:; li 31,0; 2:; lwz 3,-26524(13); mr 4,31; bl _s80042614_3; mr 30,3; li 4,-1; bl _s80042614_4; mr 29,3; li 4,-1; mr 3,30; bl _s80042614_5; mr 6,3; mr 5,29; mr 3,30; li 4,5; li 7,0; bl _s80042614_6; cmpwi 3,0; beq 5f; li 29,0; li 30,0; 3:; lwz 3,-26524(13); mr 4,30; bl _s80042614_7; cmpwi 3,0; beq 4f; lwz 3,-26524(13); mr 4,30; bl _s80042614_8; cmpw 3,31; bne 4f; li 29,1; 4:; addi 30,30,1; cmpwi 30,1; ble 3b; cmpwi 29,0; beq 0b; 5:; addi 31,31,1; cmpwi 31,4; blt 2b; li 3,-1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80042614_0();
extern "C" void _s80042614_1();
extern "C" void _s80042614_2();
extern "C" void _s80042614_3();
extern "C" void _s80042614_4();
extern "C" void _s80042614_5();
extern "C" void _s80042614_6();
extern "C" void _s80042614_7();
extern "C" void _s80042614_8();
extern "C" void f_80042614() {}
