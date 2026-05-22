// 0x802D886C EA::Allocator::GeneralAllocator::GeneralAllocator(void (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 30,3; li 29,0; li 28,1; mr 27,4; mr 24,5; stw 29,0x0(30); stw 29,0x4(30); mr 23,8; stw 28,0x8(30); mr 22,9; mr 26,6; mr 25,7; li 4,0; li 5,40; addi 3,30,12; bl _s802D886C_0; li 4,0; li 5,1024; addi 3,30,52; bl _s802D886C_1; li 4,0; li 5,16; addi 3,30,1076; bl _s802D886C_2; stw 29,0x444(30); li 4,0; stw 29,0x448(30); li 5,40; addi 3,30,1100; bl _s802D886C_3; li 9,9; li 0,10; stw 29,0x474(30); li 4,0; stw 29,0x478(30); li 5,16; stw 29,0x480(30); addi 3,30,1196; stw 29,0x488(30); stw 29,0x48c(30); stw 29,0x490(30); stw 29,0x494(30); stw 29,0x498(30); stw 29,0x49c(30); stw 29,0x4a0(30); stw 29,0x4a4(30); stw 29,0x4a8(30); stw 28,0x47c(30); stb 9,0x484(30); stb 0,0x485(30); bl _s802D886C_4; li 10,256; li 11,4096; lis 9,64; lis 0,16; stw 29,0x4fc(30); li 4,0; stw 29,0x4bc(30); li 5,32; stw 29,0x4c0(30); addi 3,30,1280; stw 29,0x4c4(30); stw 29,0x4c8(30); stw 29,0x4d0(30); stw 29,0x4d4(30); stw 29,0x4d8(30); stw 29,0x4dc(30); stw 29,0x4e0(30); stw 29,0x4e4(30); stw 29,0x4e8(30); stw 29,0x4f8(30); stw 10,0x4cc(30); stw 11,0x4ec(30); stw 9,0x4f0(30); stw 0,0x4f4(30); bl _s802D886C_5; li 9,222; li 8,205; li 3,171; lis 11,-32722; lis 10,-32722; addi 11,11,-23268; addi 10,10,-23164; li 0,221; stb 9,0x521(30); li 29,254; stb 8,0x522(30); mr 4,27; stb 3,0x523(30); mr 5,24; stw 30,0x4d4(30); mr 6,26; stw 30,0x4dc(30); mr 7,25; stb 0,0x520(30); mr 8,23; stb 29,0x524(30); mr 9,22; stw 11,0x4d0(30); mr 3,30; stw 10,0x4d8(30); bl _s802D886C_6; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s802D886C_0();
extern "C" void _s802D886C_1();
extern "C" void _s802D886C_2();
extern "C" void _s802D886C_3();
extern "C" void _s802D886C_4();
extern "C" void _s802D886C_5();
extern "C" void _s802D886C_6();
extern "C" void f_802D886C() {}
