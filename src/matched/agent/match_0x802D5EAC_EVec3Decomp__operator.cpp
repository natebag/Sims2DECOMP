// 0x802D5EAC EVec3Decomp::operator (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; cmpwi 31,116; bne 0f; lis 30,-32694; li 4,-1; addi 30,30,7444; addi 0,30,24; lwz 9,0x18(30); stw 0,0x8(1); lha 3,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; bl _s802D5EAC_0; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 30,0; beq 0f; mr 3,30; b 1f; 0:; bl _s802D5EAC_1; mr 4,31; li 5,0; bl _s802D5EAC_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D5EAC_0();
extern "C" void _s802D5EAC_1();
extern "C" void _s802D5EAC_2();
extern "C" void f_802D5EAC() {}
