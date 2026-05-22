// 0x8022E360 EIStaticSubModel::EIStaticSubModel(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; addi 29,30,128; bl _s8022E360_0; lis 9,-32697; mr 3,29; addi 9,9,-26408; stw 9,0x0(30); bl _s8022E360_1; lis 9,-32704; li 0,0; lfs f0,-4216(9); mr 3,30; stw 0,0x90(30); stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 9,0x8(1); lwz 11,0xc(1); lwz 10,0x10(1); stw 9,0x80(30); stw 0,0x7c(30); stw 0,0xa0(30); stw 0,0x98(30); stw 0,0x9c(30); stfs f0,0xc(29); stw 11,0x4(29); stw 10,0x8(29); stw 0,0xa4(30); stw 0,0x94(30); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8022E360_0();
extern "C" void _s8022E360_1();
extern "C" void f_8022E360() {}
