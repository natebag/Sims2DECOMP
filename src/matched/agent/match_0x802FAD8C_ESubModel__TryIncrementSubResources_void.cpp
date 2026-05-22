// 0x802FAD8C ESubModel::TryIncrementSubResources(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 31,0; lwz 0,0x4(29); cmpw 31,0; bge 4f; li 30,0; 0:; lwz 3,0x0(29); add 3,3,30; bl _s802FAD8C_0; cmpwi 3,0; bne 3f; addic. 30,31,-1; blt 2f; mulli 31,30,112; 1:; lwz 3,0x0(29); add 3,3,31; bl _s802FAD8C_1; addi 31,31,-112; addic. 30,30,-1; bge 1b; 2:; li 3,0; b 5f; 3:; lwz 0,0x4(29); addi 31,31,1; addi 30,30,112; cmpw 31,0; blt 0b; 4:; li 3,1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802FAD8C_0();
extern "C" void _s802FAD8C_1();
extern "C" void f_802FAD8C() {}
