// 0x801EE264 INVTarget::FormatMoneyString(int, (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-552(1); mfspr 0,8; stmw 27,0x214(1); stw 0,0x22c(1); mr 27,3; mr 29,4; mr 28,5; mr. 31,6; bne 0f; li 3,0; b 2f; 0:; addi 30,1,8; li 0,0; sth 0,0x0(31); addi 4,30,8; li 5,256; mr 3,30; bl _s801EE264_0; mr 4,30; mr 3,29; li 5,1; bl _s801EE264_1; cmpwi 28,0; beq 1f; mr 3,27; bl _s801EE264_2; cmpw 29,3; ble 1f; lis 4,-32704; mr 3,31; addi 4,4,-27664; addi 31,31,32; bl _s801EE264_3; 1:; addi 3,1,8; bl _s801EE264_4; mr 4,3; mr 3,31; bl _s801EE264_5; li 3,1; 2:; lwz 0,0x22c(1); mtspr 8,0; lmw 27,0x214(1); addi 1,1,552"
extern "C" void _s801EE264_0();
extern "C" void _s801EE264_1();
extern "C" void _s801EE264_2();
extern "C" void _s801EE264_3();
extern "C" void _s801EE264_4();
extern "C" void _s801EE264_5();
extern "C" void f_801EE264() {}
