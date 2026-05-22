// 0x8035C5AC EMsgQueue::Create(int) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 31,3; bl _s8035C5AC_0; addi 28,30,1; rlwinm 4,28,2,0,29; li 5,0; bl _s8035C5AC_1; li 0,1; stw 3,0x3c(31); stw 0,0x40(31); mr 4,30; mr 5,30; mr 3,31; bl _s8035C5AC_2; mr 29,3; mr 4,30; addi 3,31,24; li 5,0; bl _s8035C5AC_3; lwz 0,0x3c(31); mr 30,3; cmpwi 0,0; beq 0f; cmpwi 29,0; beq 0f; cmpwi 30,0; beq 0f; li 0,0; stw 28,0x38(31); stw 0,0x30(31); li 3,1; stw 0,0x34(31); b 4f; 0:; lwz 0,0x40(31); cmpwi 0,0; beq 1f; bl _s8035C5AC_4; lwz 4,0x3c(31); bl _s8035C5AC_5; li 0,0; stw 0,0x40(31); 1:; cmpwi 29,0; beq 2f; mr 3,31; bl _s8035C5AC_6; 2:; cmpwi 30,0; beq 3f; addi 3,31,24; bl _s8035C5AC_7; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035C5AC_0();
extern "C" void _s8035C5AC_1();
extern "C" void _s8035C5AC_2();
extern "C" void _s8035C5AC_3();
extern "C" void _s8035C5AC_4();
extern "C" void _s8035C5AC_5();
extern "C" void _s8035C5AC_6();
extern "C" void _s8035C5AC_7();
extern "C" void f_8035C5AC() {}
