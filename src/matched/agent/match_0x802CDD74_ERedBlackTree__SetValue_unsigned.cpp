// 0x802CDD74 ERedBlackTree::SetValue(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; bl _s802CDD74_0; mr. 4,3; beq 0f; lwz 0,0x18(4); cmpw 0,31; bne 0f; stw 29,0x1c(4); mr 3,4; b 1f; 0:; mr 3,30; mr 5,31; mr 6,29; bl _s802CDD74_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CDD74_0();
extern "C" void _s802CDD74_1();
extern "C" void f_802CDD74() {}
