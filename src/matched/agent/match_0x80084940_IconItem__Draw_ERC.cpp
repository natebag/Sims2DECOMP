// 0x80084940 IconItem::Draw(ERC (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 0,0x4(31); fmr f31,f1; andi. 9,0,1; beq 0f; lwz 0,0x30(31); cmpwi 0,0; beq 0f; cmpwi 30,0; beq 0f; lwz 9,0x1c(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; lfs f0,0x20(31); addi 10,31,32; lis 9,-32707; addi 6,1,8; stfs f0,0x8(1); lis 11,-32707; lfs f0,0x2c(31); lfs f13,0x4(10); lfs f11,0x7244(9); fmuls f0,f0,f31; stfs f13,0x4(6); lfs f12,0x7248(11); lfs f13,0x8(10); stfs f11,0xc(6); fcmpu 0,f0,f12; stfs f13,0x8(6); stfs f0,0x14(1); beq 0f; lwz 7,0x30(31); mr 3,30; addi 4,31,12; addi 5,31,20; bl _s80084940_0; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80084940_0();
extern "C" void f_80084940() {}
