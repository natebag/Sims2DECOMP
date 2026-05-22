// 0x802C9554 EMat4::Normalize(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); lis 9,-32702; mr 29,3; lfs f31,-7508(9); li 30,0; addi 31,1,8; 0:; mr 3,29; mr 4,30; addi 5,1,8; bl _s802C9554_0; lfs f0,0x8(1); fcmpu 0,f0,f31; bne 1f; lfs f0,0x4(31); fcmpu 0,f0,f31; bne 1f; lfs f0,0x8(31); fcmpu 0,f0,f31; beq 2f; 1:; mr 3,31; mr 4,31; bl _s802C9554_1; 2:; mr 4,30; mr 3,29; addi 5,1,8; addi 30,30,1; bl _s802C9554_2; cmpwi 30,2; ble 0b; mr 3,29; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s802C9554_0();
extern "C" void _s802C9554_1();
extern "C" void _s802C9554_2();
extern "C" void f_802C9554() {}
