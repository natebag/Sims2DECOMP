// 0x802D8A6C EA::Allocator::GeneralAllocator::Init(void (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 20,0x10(1); stw 0,0x44(1); mr 31,3; mr 24,4; lwz 0,0x0(31); mr 25,5; mr 23,6; mr 22,7; mr 21,8; mr 20,9; cmpwi 0,0; bne 2f; li 0,1; stw 0,0x0(31); li 4,0; li 5,1; bl _s802D8A6C_0; lwz 3,0x4fc(31); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D8A6C_1; 0:; li 0,64; li 4,0; stw 0,0x4(31); li 5,40; addi 3,31,12; addi 30,31,52; bl _s802D8A6C_2; mr 29,30; mr 3,30; li 4,0; li 5,1024; addi 27,31,1100; bl _s802D8A6C_3; addi 26,31,1196; li 0,127; addi 3,31,1076; mtspr 9,0; mr 9,29; 1:; stw 9,0x8(9); stw 9,0xc(9); addi 9,9,8; bdnz 1b; li 4,0; li 5,16; bl _s802D8A6C_4; li 30,0; stw 29,0x444(31); li 4,0; stw 30,0x448(31); li 5,40; mr 3,27; lis 28,1; bl _s802D8A6C_5; lis 29,2; lwz 0,0x4(31); li 4,0; stw 27,0x470(31); li 5,16; rlwinm 0,0,0,31,31; stw 30,0x4a8(31); ori 0,0,72; stw 27,0x46c(31); stw 30,0x474(31); mr 3,26; stw 30,0x478(31); stw 30,0x498(31); stw 30,0x49c(31); stw 28,0x4a0(31); stw 29,0x4a4(31); stw 0,0x4(31); bl _s802D8A6C_6; lwz 0,0x444(31); stw 26,0x4b8(31); stw 29,0x4e0(31); stw 28,0x4e4(31); stw 26,0x4b4(31); stw 0,0x4e8(31); bl _s802D8A6C_7; lwz 0,0x8(1); stw 3,0x4ec(31); cmpwi 0,0; beq 2f; mr 3,0; bl _s802D8A6C_8; 2:; cmpwi 24,0; bne 3f; cmpwi 25,0; beq 4f; 3:; mr 3,31; mr 4,24; mr 5,25; mr 6,23; mr 7,22; mr 8,21; mr 9,20; bl _s802D8A6C_9; 4:; li 3,1; lwz 0,0x44(1); mtspr 8,0; lmw 20,0x10(1); addi 1,1,64"
extern "C" void _s802D8A6C_0();
extern "C" void _s802D8A6C_1();
extern "C" void _s802D8A6C_2();
extern "C" void _s802D8A6C_3();
extern "C" void _s802D8A6C_4();
extern "C" void _s802D8A6C_5();
extern "C" void _s802D8A6C_6();
extern "C" void _s802D8A6C_7();
extern "C" void _s802D8A6C_8();
extern "C" void _s802D8A6C_9();
extern "C" void f_802D8A6C() {}
