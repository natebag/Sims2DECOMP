// 0x800BD9CC IFFResMap::CountNodes(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 5,0; bl _s800BD9CC_0; lwz 0,0x4(30); cmpw 3,0; beq 0f; lwz 9,0x0(3); lis 0,-17874; lwz 3,0x4(3); ori 0,0,35747; subf 3,9,3; mullw 3,3,0; srawi 3,3,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BD9CC_0();
extern "C" void f_800BD9CC() {}
