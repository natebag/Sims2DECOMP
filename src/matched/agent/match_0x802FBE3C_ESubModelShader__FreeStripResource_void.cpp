// 0x802FBE3C ESubModelShader::FreeStripResource(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 9,31,20; lwz 0,0x4(9); cmpw 30,0; bge 1f; mr 28,9; li 29,0; 0:; lwz 4,0x14(31); mr 3,31; addi 30,30,1; add 4,4,29; bl _s802FBE3C_0; addi 29,29,52; lwz 0,0x4(28); cmpw 30,0; blt 0b; 1:; addi 3,31,20; bl _s802FBE3C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802FBE3C_0();
extern "C" void _s802FBE3C_1();
extern "C" void f_802FBE3C() {}
