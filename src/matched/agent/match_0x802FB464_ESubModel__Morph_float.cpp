// 0x802FB464 ESubModel::Morph(float (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 0,0x4(31); li 3,0; li 29,0; cmpw 3,0; bge 1f; li 30,0; 0:; lwz 3,0x0(31); mr 4,28; addi 29,29,1; add 3,3,30; bl _s802FB464_0; addi 30,30,112; lwz 0,0x4(31); cmpw 29,0; blt 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802FB464_0();
extern "C" void f_802FB464() {}
