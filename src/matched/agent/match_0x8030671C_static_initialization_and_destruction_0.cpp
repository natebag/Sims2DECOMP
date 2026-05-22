// 0x8030671C __static_initialization_and_destruction_0 (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 1f; lis 30,-32693; lis 9,-32697; addi 9,9,-24288; addi 28,30,3420; stw 9,0xd5c(30); mr 3,28; li 4,2; addi 29,28,4; bl _s8030671C_0; li 31,1; lis 9,-32697; addi 9,9,-20760; stw 9,0xd5c(30); 0:; mr 3,29; li 4,4096; bl _s8030671C_1; addi 29,29,24; cmpwi 31,0; addi 31,31,-1; bne 0b; li 0,0; stw 0,0x34(28); b 2f; 1:; lis 3,-32693; li 4,2; addi 3,3,3420; bl _s8030671C_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8030671C_0();
extern "C" void _s8030671C_1();
extern "C" void _s8030671C_2();
extern "C" void f_8030671C() {}
