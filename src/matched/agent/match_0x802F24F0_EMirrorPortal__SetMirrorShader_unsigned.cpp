// 0x802F24F0 EMirrorPortal::SetMirrorShader(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x44(31); cmpwi 3,0; beq 0f; bl _s802F24F0_0; li 0,0; stw 0,0x44(31); 0:; lis 3,-32692; mr 4,30; addi 3,3,-17444; li 5,0; li 6,0; bl _s802F24F0_1; stw 3,0x44(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F24F0_0();
extern "C" void _s802F24F0_1();
extern "C" void f_802F24F0() {}
