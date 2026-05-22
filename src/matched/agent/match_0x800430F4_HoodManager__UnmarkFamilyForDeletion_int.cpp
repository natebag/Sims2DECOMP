// 0x800430F4 HoodManager::UnmarkFamilyForDeletion(int, (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); addi 26,3,1; mr 27,4; lwz 3,-32056(13); li 5,0; li 6,0; mr 4,26; bl _s800430F4_0; li 28,0; lwz 3,-32056(13); mr 4,26; bl _s800430F4_1; lis 3,1; ori 3,3,24584; bl _s800430F4_2; bl _s800430F4_3; mr 29,3; lwz 4,-32056(13); bl _s800430F4_4; lwz 3,-32056(13); mr 4,26; bl _s800430F4_5; addis 11,29,1; lwz 0,0x6004(11); cmpw 28,0; bge 2f; li 25,0; li 30,0; 0:; addi 9,11,-32744; lwzx 9,9,30; cmpwi 9,0; beq 1f; lwz 10,0x38(9); cmpwi 10,0; beq 1f; addi 31,11,-32740; lwzx 0,31,30; cmpwi 0,0; beq 1f; lwz 9,0x0(27); lwz 4,0x1c(10); lha 3,0x58(9); lwz 0,0x5c(9); add 3,27,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; stwx 25,31,30; 1:; addis 11,29,1; addi 28,28,1; lwz 0,0x6004(11); addi 30,30,28; cmpw 28,0; blt 0b; 2:; lwz 4,-32056(13); mr 3,29; lwz 5,-32040(13); bl _s800430F4_6; lwz 3,-32056(13); mr 4,26; li 5,0; bl _s800430F4_7; lwz 3,-32056(13); mr 4,26; bl _s800430F4_8; cmpwi 29,0; beq 3f; mr 3,29; li 4,3; bl _s800430F4_9; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800430F4_0();
extern "C" void _s800430F4_1();
extern "C" void _s800430F4_2();
extern "C" void _s800430F4_3();
extern "C" void _s800430F4_4();
extern "C" void _s800430F4_5();
extern "C" void _s800430F4_6();
extern "C" void _s800430F4_7();
extern "C" void _s800430F4_8();
extern "C" void _s800430F4_9();
extern "C" void f_800430F4() {}
