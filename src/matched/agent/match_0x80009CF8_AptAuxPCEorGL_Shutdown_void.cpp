// 0x80009CF8 AptAuxPCEorGL_Shutdown(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 3,-32732(13); cmpwi 3,0; beq 0f; bl _s80009CF8_0; li 0,0; stw 0,-32732(13); 0:; lwz 0,-25172(13); cmpwi 0,0; beq 1f; bl _s80009CF8_1; lwz 4,-25172(13); bl _s80009CF8_2; 1:; bl _s80009CF8_3; li 30,0; lis 3,-32697; li 4,0; li 5,10000; addi 3,3,3472; bl _s80009CF8_4; lis 3,-32697; li 4,0; li 5,1024; addi 3,3,-1792; bl _s80009CF8_5; lis 3,-32697; li 4,0; li 5,1536; addi 3,3,-6160; stw 30,-32740(13); bl _s80009CF8_6; lis 3,-32697; li 4,0; li 5,40; addi 3,3,-768; bl _s80009CF8_7; lwz 3,-32708(13); bl _s80009CF8_8; stw 30,-32708(13); addi 3,13,-25156; bl _s80009CF8_9; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80009CF8_0();
extern "C" void _s80009CF8_1();
extern "C" void _s80009CF8_2();
extern "C" void _s80009CF8_3();
extern "C" void _s80009CF8_4();
extern "C" void _s80009CF8_5();
extern "C" void _s80009CF8_6();
extern "C" void _s80009CF8_7();
extern "C" void _s80009CF8_8();
extern "C" void _s80009CF8_9();
extern "C" void f_80009CF8() {}
