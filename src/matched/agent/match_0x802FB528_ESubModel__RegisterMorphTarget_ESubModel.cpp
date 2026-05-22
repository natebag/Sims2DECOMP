// 0x802FB528 ESubModel::RegisterMorphTarget(ESubModel (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,4; lwz 0,0x4(30); li 3,0; mr 28,5; li 29,0; cmpw 3,0; bge 1f; li 31,0; 0:; lwz 3,0x0(30); mr 5,28; lwz 4,0x0(27); addi 29,29,1; add 3,3,31; add 4,4,31; bl _s802FB528_0; addi 31,31,112; lwz 0,0x4(30); cmpw 29,0; blt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802FB528_0();
extern "C" void f_802FB528() {}
