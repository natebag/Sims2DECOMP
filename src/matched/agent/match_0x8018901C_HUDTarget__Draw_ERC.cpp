// 0x8018901C HUDTarget::Draw(ERC (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; addi 30,31,1856; mr 3,30; bl _s8018901C_0; addi 3,31,264; bl _s8018901C_1; mr 3,30; mr 4,29; bl _s8018901C_2; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; addi 30,31,2036; mr 3,30; bl _s8018901C_3; addi 3,31,1060; bl _s8018901C_4; mr 3,30; mr 4,29; bl _s8018901C_5; 0:; lis 9,-32697; lwz 0,0x6118(9); cmpwi 0,0; beq 1f; mr 3,31; mr 4,29; li 5,0; bl _s8018901C_6; mr 3,31; mr 4,29; li 5,1; bl _s8018901C_7; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8018901C_0();
extern "C" void _s8018901C_1();
extern "C" void _s8018901C_2();
extern "C" void _s8018901C_3();
extern "C" void _s8018901C_4();
extern "C" void _s8018901C_5();
extern "C" void _s8018901C_6();
extern "C" void _s8018901C_7();
extern "C" void f_8018901C() {}
