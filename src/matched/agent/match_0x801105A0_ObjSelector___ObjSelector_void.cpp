// 0x801105A0 ObjSelector::~ObjSelector(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 11,0x64(31); mr 29,4; cmpw 30,11; beq 1f; cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 0:; stw 30,0x64(31); 1:; lwz 11,0x64(31); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 3,0x5c(31); cmpwi 3,0; beq 3f; bl _s801105A0_0; 3:; lwz 11,0x3c(31); cmpwi 11,0; beq 4f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; addi 3,31,28; li 4,2; bl _s801105A0_1; andi. 0,29,1; beq 5f; mr 3,31; bl _s801105A0_2; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801105A0_0();
extern "C" void _s801105A0_1();
extern "C" void _s801105A0_2();
extern "C" void f_801105A0() {}
