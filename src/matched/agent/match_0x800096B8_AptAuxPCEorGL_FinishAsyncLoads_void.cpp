// 0x800096B8 AptAuxPCEorGL_FinishAsyncLoads(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); lwz 0,-32740(13); li 26,0; cmpw 26,0; bge 5f; lis 9,-32697; addi 28,1,8; addi 27,9,-1792; li 25,0; li 29,0; 0:; lwzx 9,29,27; lwz 3,0x104(9); stw 3,0x8(1); cmpwi 3,0; beq 1f; bl _s800096B8_0; 1:; lwzx 9,29,27; mr 3,28; lwz 6,0x100(9); lwz 4,0x108(9); lwz 5,0x10c(9); bl _s800096B8_1; lwzx 31,29,27; stw 25,0x8(1); addi 30,31,260; cmpw 28,30; beq 3f; lwz 3,0x104(31); cmpwi 3,0; beq 2f; bl _s800096B8_2; cmpwi 3,0; bne 2f; lwz 3,0x104(31); bl _s800096B8_3; 2:; lwz 3,0x0(28); stw 3,0x0(30); cmpwi 3,0; beq 3f; bl _s800096B8_4; 3:; lwz 3,0x8(1); cmpwi 3,0; beq 4f; bl _s800096B8_5; cmpwi 3,0; bne 4f; lwz 3,0x8(1); bl _s800096B8_6; 4:; bl _s800096B8_7; addi 26,26,1; lwzx 4,29,27; addi 29,29,4; bl _s800096B8_8; lwz 0,-32740(13); cmpw 26,0; blt 0b; 5:; li 0,0; stw 0,-32740(13); lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s800096B8_0();
extern "C" void _s800096B8_1();
extern "C" void _s800096B8_2();
extern "C" void _s800096B8_3();
extern "C" void _s800096B8_4();
extern "C" void _s800096B8_5();
extern "C" void _s800096B8_6();
extern "C" void _s800096B8_7();
extern "C" void _s800096B8_8();
extern "C" void f_800096B8() {}
