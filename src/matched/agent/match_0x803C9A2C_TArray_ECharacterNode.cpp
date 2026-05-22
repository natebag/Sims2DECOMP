// 0x803C9A2C TArray<ECharacterNode, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); lwz 4,0x4(30); bl _s803C9A2C_0; lis 3,-32693; lwz 4,0x0(30); addi 3,3,21144; bl _s803C9A2C_1; mr 3,30; bl _s803C9A2C_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C9A2C_0();
extern "C" void _s803C9A2C_1();
extern "C" void _s803C9A2C_2();
extern "C" void f_803C9A2C() {}
