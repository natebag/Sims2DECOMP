// 0x8005635C ISimInstance::ISimInstance(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; bl _s8005635C_0; lis 9,-32698; lis 11,-32698; addi 9,9,-14656; addi 11,11,-14600; stw 9,0x320(30); addi 3,30,820; stw 11,0x0(30); bl _s8005635C_1; lis 9,-32707; lis 10,-32707; lfs f0,0x3734(9); addi 11,1,8; lfs f13,0x3738(10); li 0,0; stfs f0,0x8(1); lis 7,-32696; stfs f13,0x8(11); addi 9,7,21564; stfs f13,0x4(11); lis 4,-32696; lwz 6,0x8(11); addi 5,4,21812; lwz 10,0x8(1); mr 3,30; lwz 8,0x4(11); stw 0,0x328(30); stw 0,0x32c(30); stw 10,0x543c(7); stw 6,0x8(9); stw 10,0x5534(4); stw 6,0x8(5); stw 8,0x4(9); stw 8,0x4(5); stw 0,0xf0(9); stw 0,0xf4(9); stw 0,0x3b0(30); stw 0,0x3bc(30); stw 0,0x3c0(30); stw 0,0x3ac(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8005635C_0();
extern "C" void _s8005635C_1();
extern "C" void f_8005635C() {}
