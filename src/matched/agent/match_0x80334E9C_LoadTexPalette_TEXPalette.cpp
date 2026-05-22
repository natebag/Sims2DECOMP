// 0x80334E9C LoadTexPalette(TEXPalette (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 30,3; mr 31,4; 0:; mr 3,31; addi 4,1,8; bl _s80334E9C_0; cmpwi 3,0; beq 0b; bl _s80334E9C_1; lwz 4,0x3c(1); li 5,32; li 6,0; li 7,0; bl _s80334E9C_2; lwz 5,0x3c(1); mr 4,3; stw 3,0x0(30); li 6,0; addi 5,5,31; li 7,2; rlwinm 5,5,0,0,26; addi 3,1,8; bl _s80334E9C_3; addi 3,1,8; bl _s80334E9C_4; lwz 3,0x0(30); bl _s80334E9C_5; li 3,1; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s80334E9C_0();
extern "C" void _s80334E9C_1();
extern "C" void _s80334E9C_2();
extern "C" void _s80334E9C_3();
extern "C" void _s80334E9C_4();
extern "C" void _s80334E9C_5();
extern "C" void f_80334E9C() {}
