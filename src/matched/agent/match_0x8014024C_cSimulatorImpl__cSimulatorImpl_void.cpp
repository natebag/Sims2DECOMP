// 0x8014024C cSimulatorImpl::cSimulatorImpl(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 31,3; addi 9,9,18432; addi 3,31,4; stw 9,0x0(31); addi 30,31,180; bl _s8014024C_0; li 29,4; lis 9,-32698; lis 11,-32698; addi 9,9,17976; addi 11,11,18008; li 0,0; stw 9,0x10(31); stw 11,0x0(31); stw 0,0x98(31); 0:; mr 3,30; bl _s8014024C_1; addi 30,30,32; cmpwi 29,0; addi 29,29,-1; bne 0b; addi 3,31,340; bl _s8014024C_2; lis 9,-32706; lis 11,-32706; lfs f0,-10696(9); li 0,0; lfs f13,-10692(11); li 9,3500; li 11,1; stw 9,0x84(31); stfs f0,0xb0(31); mr 3,31; stfs f13,0xa4(31); sth 11,0x36(31); sth 0,0x3a(31); stfs f0,0xa0(31); stw 0,0x80(31); stw 0,0x8c(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x17c(31); stfs f0,0xac(31); stw 0,0x174(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8014024C_0();
extern "C" void _s8014024C_1();
extern "C" void _s8014024C_2();
extern "C" void f_8014024C() {}
