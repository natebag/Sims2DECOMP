// 0x8036311C EDL::Validate(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8036311C_0; addi 3,30,24; bl _s8036311C_1; lwz 31,0x30(30); cmpwi 31,0; beq 2f; 0:; lwz 11,0x0(31); cmpwi 11,0; beq 1f; lwz 9,0x24(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 2:; lwz 31,0x3c(30); cmpwi 31,0; beq 4f; 3:; lwz 3,0x0(31); bl _s8036311C_2; lwz 31,0x8(31); cmpwi 31,0; bne 3b; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8036311C_0();
extern "C" void _s8036311C_1();
extern "C" void _s8036311C_2();
extern "C" void f_8036311C() {}
