// 0x8004DFD4 ISimsObjectModel::KillAllAnimTracks(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; addi 3,31,820; bl _s8004DFD4_0; lwz 4,0x4b4(31); stw 30,0x3e8(31); cmpwi 4,0; beq 0f; lis 3,-32693; addi 3,3,11064; bl _s8004DFD4_1; stw 30,0x4b4(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004DFD4_0();
extern "C" void _s8004DFD4_1();
extern "C" void f_8004DFD4() {}
