// 0x801521AC cFixedWorldImpl::GetRoomIdFromPoint(CTilePt (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 29,0x54(1); stw 0,0x64(1); mr 30,3; mr 29,4; lwz 9,0x0(30); lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,-21472(13); mr 31,3; cmpwi 9,0; bne 0f; li 3,0; b 3f; 0:; li 0,0; ori 0,0,65531; cmpw 31,0; bne 2f; addi 5,1,64; addi 6,1,68; addi 7,1,72; addi 8,1,76; mr 4,29; mr 3,9; bl _s801521AC_0; lwz 9,0x0(30); addi 3,1,8; mr 5,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,30,4; mtspr 8,0; blrl; addi 3,1,8; li 4,32; bl _s801521AC_1; cmpwi 3,0; bne 1f; addi 3,1,8; li 4,16; bl _s801521AC_2; 1:; lwz 9,0x40(1); lhz 31,0x0(9); addi 3,1,8; li 4,2; bl _s801521AC_3; 2:; mr 3,31; 3:; lwz 0,0x64(1); mtspr 8,0; lmw 29,0x54(1); addi 1,1,96"
extern "C" void _s801521AC_0();
extern "C" void _s801521AC_1();
extern "C" void _s801521AC_2();
extern "C" void _s801521AC_3();
extern "C" void f_801521AC() {}
