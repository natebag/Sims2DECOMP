// 0x8021D250 InteractorModule::SimInteractor::SimInteractor(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 31,3; li 29,9; addi 30,31,100; bl _s8021D250_0; lis 9,-32697; addi 9,9,-31264; stw 9,0x5c(31); 0:; mr 3,30; bl _s8021D250_1; addi 30,30,28; cmpwi 29,0; addi 29,29,-1; bne 0b; lis 9,-32704; li 30,0; lfs f31,-9108(9); addi 3,31,416; stw 29,0x190(31); stw 30,0x17c(31); stfs f31,0x180(31); stfs f31,0x184(31); stw 30,0x188(31); stw 30,0x18c(31); stw 30,0x19c(31); bl _s8021D250_2; addi 9,31,464; lis 11,-32704; stfs f31,0x4(9); addi 10,31,492; stfs f31,0x8(9); addi 8,31,480; stfs f31,0x8(1); addi 7,31,504; stfs f31,0x10(1); addi 6,31,516; stfs f31,0xc(1); mr 3,31; lwz 0,0x8(1); lfs f0,-9104(11); lwz 11,0xc(1); lwz 9,0x10(1); stw 0,0x1ec(31); stfs f0,0x1dc(31); stfs f31,0x1d0(31); stw 9,0x8(10); stw 11,0x4(10); lwz 0,0x1ec(31); stw 0,0x1e0(31); stw 9,0x8(8); stw 11,0x4(8); stfs f31,0x4(7); stfs f31,0x8(7); stfs f31,0x1f8(31); stfs f31,0x4(6); stfs f31,0x8(6); stfs f31,0x204(31); stw 30,0x228(31); stw 30,0x224(31); lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s8021D250_0();
extern "C" void _s8021D250_1();
extern "C" void _s8021D250_2();
extern "C" void f_8021D250() {}
