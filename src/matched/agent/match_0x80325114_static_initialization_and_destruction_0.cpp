// 0x80325114 __static_initialization_and_destruction_0 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 30,-32692; addi 30,30,-24196; mr 3,30; bl _s80325114_0; lis 9,-32697; li 0,1; addi 9,9,-17272; stw 0,0x54(30); stw 9,0xd1c(30); b 1f; 0:; lis 3,-32692; li 4,2; addi 3,3,-24196; bl _s80325114_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80325114_0();
extern "C" void _s80325114_1();
extern "C" void f_80325114() {}
