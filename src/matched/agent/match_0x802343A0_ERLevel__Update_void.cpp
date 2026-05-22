// 0x802343A0 ERLevel::Update(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; bl _s802343A0_0; mr 3,30; bl _s802343A0_1; addis 30,30,3; lwz 9,-23948(30); 0:; cmpwi 9,0; b 3f; 1:; lwz 11,0x1c(9); lwz 30,0x10(9); lwz 0,0x5c(11); andi. 9,0,16; bne 2f; lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr. 9,30; 3:; beq 4f; lwz 0,0x18(9); cmpw 0,31; beq 1b; cmpwi 9,0; beq 4f; lwz 31,0x18(9); b 0b; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802343A0_0();
extern "C" void _s802343A0_1();
extern "C" void f_802343A0() {}
