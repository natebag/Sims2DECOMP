// 0x800A6308 MemFile::Flush(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; bl _s800A6308_0; cmpwi 3,0; bne 0f; li 3,-49; b 4f; 0:; lwz 0,0x10c(30); cmpwi 0,0; beq 3f; lwz 0,0x110(30); cmpwi 0,0; beq 3f; lis 9,-32688; mr 3,30; addi 29,9,-1852; bl _s800A6308_1; mr 4,3; li 5,1; mr 3,29; bl _s800A6308_2; mr. 31,3; bne 2f; mr 3,30; bl _s800A6308_3; mr 4,3; mr 3,29; bl _s800A6308_4; cmpwi 3,0; beq 1f; mr 3,30; bl _s800A6308_5; mr 4,3; li 5,1; mr 3,29; bl _s800A6308_6; mr 31,3; 1:; cmpwi 31,0; beq 3f; 2:; lwz 9,0x0(31); lwz 5,0x120(30); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; lwz 4,0x114(30); add 3,31,3; blrl; lwz 9,0x0(31); lwz 4,0x120(30); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lis 3,-32688; mr 4,31; addi 3,3,-1852; bl _s800A6308_7; li 0,0; stw 0,0x110(30); 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A6308_0();
extern "C" void _s800A6308_1();
extern "C" void _s800A6308_2();
extern "C" void _s800A6308_3();
extern "C" void _s800A6308_4();
extern "C" void _s800A6308_5();
extern "C" void _s800A6308_6();
extern "C" void _s800A6308_7();
extern "C" void f_800A6308() {}
