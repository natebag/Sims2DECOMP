// 0x800AD89C cBoxX::Shutdown(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x64(31); cmpwi 3,0; beq 1f; bl _s800AD89C_0; lwz 3,0x64(31); cmpwi 3,0; beq 0f; li 4,3; bl _s800AD89C_1; 0:; li 0,0; stw 0,0x64(31); 1:; lwz 3,-24136(13); cmpwi 3,0; beq 3f; bl _s800AD89C_2; lwz 3,-24136(13); cmpwi 3,0; beq 2f; li 4,3; bl _s800AD89C_3; 2:; li 0,0; stw 0,-24136(13); 3:; lwz 9,0x10(31); cmpwi 9,0; beq 4f; li 30,0; stw 30,0x0(9); lwz 3,0x10(31); bl _s800AD89C_4; lwz 3,0x10(31); bl _s800AD89C_5; stw 30,0x10(31); 4:; li 0,0; li 3,1; stw 0,-32088(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800AD89C_0();
extern "C" void _s800AD89C_1();
extern "C" void _s800AD89C_2();
extern "C" void _s800AD89C_3();
extern "C" void _s800AD89C_4();
extern "C" void _s800AD89C_5();
extern "C" void f_800AD89C() {}
