// 0x80366A04 ERAmbientSound::~ERAmbientSound(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x24(31); addi 9,31,36; cmpwi 3,0; beq 1f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s80366A04_0; b 1f; 0:; bl _s80366A04_1; 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s80366A04_2; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80366A04_0();
extern "C" void _s80366A04_1();
extern "C" void _s80366A04_2();
extern "C" void f_80366A04() {}
