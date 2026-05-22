// 0x8012B6D8 cXPersonImpl::Turn(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); bl _s8012B6D8_0; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x188(9); lwz 9,0x18c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; bl _s8012B6D8_1; stfs f1,0x30(30); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8012B6D8_0();
extern "C" void _s8012B6D8_1();
extern "C" void f_8012B6D8() {}
