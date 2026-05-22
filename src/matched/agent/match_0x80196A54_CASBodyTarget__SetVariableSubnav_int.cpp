// 0x80196A54 CASBodyTarget::SetVariableSubnav(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 5,5; beq 3f; cmpwi 4,1; beq 1f; bgt 0f; cmpwi 4,0; beq 2f; b 3f; 0:; cmpwi 4,4; bne 3f; mr 4,5; bl _s80196A54_0; b 3f; 1:; mr 4,5; bl _s80196A54_1; b 3f; 2:; mr 4,5; bl _s80196A54_2; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80196A54_0();
extern "C" void _s80196A54_1();
extern "C" void _s80196A54_2();
extern "C" void f_80196A54() {}
