// 0x8007D79C GetTimeDate(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); bl _s8007D79C_0; addi 5,1,8; bl _s8007D79C_1; lwz 3,0x10(1); lwz 10,0xc(1); mulli 3,3,3600; lwz 0,0x1c(1); lwz 9,0x18(1); mulli 10,10,60; lwz 11,0x14(1); lwz 8,0x8(1); rlwinm 0,0,26,0,5; rlwinm 9,9,22,6,9; rlwinm 11,11,17,10,14; or 0,0,9; add 3,3,10; or 0,0,11; add 3,3,8; rlwinm 3,3,0,15,31; or 3,0,3; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s8007D79C_0();
extern "C" void _s8007D79C_1();
extern "C" void f_8007D79C() {}
