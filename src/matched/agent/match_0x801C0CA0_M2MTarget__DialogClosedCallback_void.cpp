// 0x801C0CA0 M2MTarget::DialogClosedCallback(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x11c(31); cmpwi 0,1; beq 0f; cmpwi 0,5; bne 1f; lis 3,-32705; li 4,7; addi 3,3,8412; bl _s801C0CA0_0; mr 3,31; bl _s801C0CA0_1; li 0,3; stw 0,0x168(31); b 1f; 0:; mr 3,31; bl _s801C0CA0_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C0CA0_0();
extern "C" void _s801C0CA0_1();
extern "C" void _s801C0CA0_2();
extern "C" void f_801C0CA0() {}
