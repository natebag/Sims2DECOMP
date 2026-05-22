// 0x800105D8 AptViewer::Init(UIObjectBase (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x3a0(31); cmpwi 0,0; bne 0f; bl _s800105D8_0; 0:; li 0,1; mr 3,30; stw 0,0x3a0(31); bl _s800105D8_1; addi 0,31,1104; li 9,0; addi 3,31,1108; 1:; stw 9,0x0(3); addi 3,3,-4; cmpw 3,0; bge 1b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800105D8_0();
extern "C" void _s800105D8_1();
extern "C" void f_800105D8() {}
