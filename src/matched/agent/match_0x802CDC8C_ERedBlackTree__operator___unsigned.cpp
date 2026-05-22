// 0x802CDC8C ERedBlackTree::operator[](unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s802CDC8C_0; mr. 4,3; beq 0f; lwz 0,0x18(4); cmpw 0,31; bne 0f; addi 3,4,28; b 1f; 0:; mr 3,30; mr 5,31; li 6,0; bl _s802CDC8C_1; addi 3,3,28; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CDC8C_0();
extern "C" void _s802CDC8C_1();
extern "C" void f_802CDC8C() {}
