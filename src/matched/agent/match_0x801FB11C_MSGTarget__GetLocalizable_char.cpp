// 0x801FB11C MSGTarget::GetLocalizable(char (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,8192; bl _s801FB11C_0; mr 31,3; li 0,0; sth 0,0x0(31); lbz 9,0x0(30); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32704; mr 4,30; addi 3,3,-21316; bl _s801FB11C_1; cmpwi 3,0; bne 1f; addi 3,29,140; b 2f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-21300; bl _s801FB11C_2; cmpwi 3,0; bne 3f; addi 3,29,144; 2:; bl _s801FB11C_3; mr 4,3; mr 3,31; bl _s801FB11C_4; b 4f; 3:; lis 3,-32704; mr 4,30; addi 3,3,-21284; bl _s801FB11C_5; cmpwi 3,0; bne 4f; addi 3,29,148; bl _s801FB11C_6; mr 4,3; mr 3,31; bl _s801FB11C_7; 4:; mr 3,31; bl _s801FB11C_8; mr 3,31; bl _s801FB11C_9; mr 3,31; bl _s801FB11C_10; mr 3,31; bl _s801FB11C_11; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801FB11C_12; mr 30,3; mr 4,31; bl _s801FB11C_13; mr 3,31; bl _s801FB11C_14; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801FB11C_0();
extern "C" void _s801FB11C_1();
extern "C" void _s801FB11C_2();
extern "C" void _s801FB11C_3();
extern "C" void _s801FB11C_4();
extern "C" void _s801FB11C_5();
extern "C" void _s801FB11C_6();
extern "C" void _s801FB11C_7();
extern "C" void _s801FB11C_8();
extern "C" void _s801FB11C_9();
extern "C" void _s801FB11C_10();
extern "C" void _s801FB11C_11();
extern "C" void _s801FB11C_12();
extern "C" void _s801FB11C_13();
extern "C" void _s801FB11C_14();
extern "C" void f_801FB11C() {}
