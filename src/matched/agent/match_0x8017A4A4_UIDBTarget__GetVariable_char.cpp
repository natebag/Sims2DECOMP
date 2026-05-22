// 0x8017A4A4 UIDBTarget::GetVariable(char (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stmw 28,0x108(1); stw 0,0x11c(1); mr 29,4; mr 3,29; bl _s8017A4A4_0; mr. 28,3; beq 9f; cmpwi 29,0; beq 9f; li 3,32; addi 30,1,136; bl _s8017A4A4_1; li 0,0; mr 31,3; stb 0,0x0(31); li 10,0; stb 0,0x88(1); li 8,0; stb 0,0x8(1); li 11,0; li 9,0; cmpw 10,28; bge 4f; addi 7,1,8; li 5,0; mr 6,30; 0:; lbzx 0,29,10; cmpwi 0,58; bne 1f; addi 8,8,1; b 3f; 1:; cmpwi 8,1; bne 2f; stbx 0,7,11; addi 11,11,1; stbx 5,7,11; b 3f; 2:; cmpwi 8,2; bne 3f; stbx 0,6,9; addi 9,9,1; stbx 5,6,9; 3:; addi 10,10,1; cmpw 10,28; blt 0b; 4:; addi 3,1,8; bl _s8017A4A4_2; mr 3,30; bl _s8017A4A4_3; lbz 0,0x8(1); extsb 0,0; cmpwi 0,105; bne 5f; mr 3,30; bl _s8017A4A4_4; mr 5,3; lis 4,-32706; addi 4,4,11364; mr 3,31; crxor 6,6,6; bl _s8017A4A4_5; b 6f; 5:; cmpwi 0,102; bne 7f; mr 3,30; bl _s8017A4A4_6; lis 4,-32706; addi 4,4,11368; mr 3,31; creqv 6,6,6; bl _s8017A4A4_7; 6:; mr 3,31; bl _s8017A4A4_8; mr 3,31; b 10f; 7:; cmpwi 0,115; bne 8f; mr 3,30; bl _s8017A4A4_9; mr. 29,3; beq 8f; li 3,8192; bl _s8017A4A4_10; mr 30,3; mr 3,29; bl _s8017A4A4_11; addi 4,3,1; mr 5,30; mr 3,29; bl _s8017A4A4_12; mr 3,31; bl _s8017A4A4_13; mr 3,30; bl _s8017A4A4_14; mr 3,30; b 10f; 8:; mr 3,31; bl _s8017A4A4_15; 9:; li 3,0; 10:; lwz 0,0x11c(1); mtspr 8,0; lmw 28,0x108(1); addi 1,1,280"
extern "C" void _s8017A4A4_0();
extern "C" void _s8017A4A4_1();
extern "C" void _s8017A4A4_2();
extern "C" void _s8017A4A4_3();
extern "C" void _s8017A4A4_4();
extern "C" void _s8017A4A4_5();
extern "C" void _s8017A4A4_6();
extern "C" void _s8017A4A4_7();
extern "C" void _s8017A4A4_8();
extern "C" void _s8017A4A4_9();
extern "C" void _s8017A4A4_10();
extern "C" void _s8017A4A4_11();
extern "C" void _s8017A4A4_12();
extern "C" void _s8017A4A4_13();
extern "C" void _s8017A4A4_14();
extern "C" void _s8017A4A4_15();
extern "C" void f_8017A4A4() {}
