// 0x802FB8E0 ESubModel::TransformModelUV(EVec2 (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; li 31,0; lwz 0,0x4(29); mr 23,4; mr 24,5; mr 25,6; mr 26,7; mr 27,8; mr 28,9; cmpw 31,0; bge 1f; li 30,0; 0:; lwz 3,0x0(29); mr 4,23; mr 5,24; mr 6,25; add 3,3,30; mr 7,26; mr 8,27; mr 9,28; bl _s802FB8E0_0; addi 31,31,1; lwz 0,0x4(29); addi 30,30,112; cmpw 31,0; blt 0b; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s802FB8E0_0();
extern "C" void f_802FB8E0() {}
