// 0x8009427C PreGameState::Reset(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 0,3; lis 30,-32697; lis 3,-32706; stw 0,0x5b84(30); li 4,0; addi 30,30,23428; addi 3,3,-31448; bl _s8009427C_0; li 0,0; li 9,1; stw 0,0xc(29); mr 3,30; stw 9,0x28(29); li 4,0; stw 0,0x1c(29); li 5,2; stw 0,0x20(29); stw 0,0x24(29); stw 9,0x2c(29); bl _s8009427C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009427C_0();
extern "C" void _s8009427C_1();
extern "C" void f_8009427C() {}
