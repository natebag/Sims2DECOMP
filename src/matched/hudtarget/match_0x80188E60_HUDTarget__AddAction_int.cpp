// 0x80188E60 HUDTarget::AddAction(int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 23,0x24(1); stw 0,0x4c(1); mr 26,4; mr 24,3; mulli 11,26,796; mr 23,9; mr 25,5; mr 27,7; mr 30,8; li 9,1; add 11,11,24; lwz 0,0x10c(11); cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 4f; addi 31,1,8; li 29,0; li 0,0; stw 29,0x8(31); stb 0,0x11(31); mr 3,31; li 4,0; li 5,0; li 6,0; li 7,0; bl _s80188E60_0; lwz 28,0x38(25); cmpwi 30,0; stw 29,0x8(1); stw 27,0x4(31); beq 1f; mr 3,30; bl _s80188E60_1; 1:; lwz 3,0x8(31); cmpwi 3,0; beq 2f; bl _s80188E60_2; stw 29,0x8(31); 2:; mulli 3,26,796; stw 30,0x8(31); stw 28,0xc(31); mr 5,25; mr 6,23; mr 4,31; addi 3,3,264; add 3,24,3; bl _s80188E60_3; lwz 0,0x8(1); cmpwi 0,0; beq 3f; bl _s80188E60_4; lwz 4,0x8(1); bl _s80188E60_5; stw 29,0x8(1); 3:; lwz 3,0x8(31); cmpwi 3,0; beq 4f; bl _s80188E60_6; stw 29,0x8(31); 4:; lwz 0,0x4c(1); mtspr 8,0; lmw 23,0x24(1); addi 1,1,72"

extern "C" void _s80188E60_0();
extern "C" void _s80188E60_1();
extern "C" void _s80188E60_2();
extern "C" void _s80188E60_3();
extern "C" void _s80188E60_4();
extern "C" void _s80188E60_5();
extern "C" void _s80188E60_6();

struct HUDTarget {
    void AddAction();
};

void HUDTarget::AddAction() {
}
