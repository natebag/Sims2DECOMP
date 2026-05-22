// 0x8000AB8C AptAuxPCEorGL_LoadFile(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 11,-26824(13); mr 29,3; addi 30,1,8; lwz 9,0x338(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s8000AB8C_0; lis 4,-32707; mr 3,30; addi 4,4,-10992; bl _s8000AB8C_1; lis 4,-32707; mr 3,30; addi 4,4,-11604; bl _s8000AB8C_2; mr 4,29; mr 3,30; bl _s8000AB8C_3; lwz 3,0x8(1); lis 4,-32707; addi 4,4,-10984; bl _s8000AB8C_4; lwz 4,0x8(1); mr 3,30; bl _s8000AB8C_5; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8000AB8C_0();
extern "C" void _s8000AB8C_1();
extern "C" void _s8000AB8C_2();
extern "C" void _s8000AB8C_3();
extern "C" void _s8000AB8C_4();
extern "C" void _s8000AB8C_5();
extern "C" void f_8000AB8C() {}
