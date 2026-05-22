// 0x8039ED4C void (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; mr 27,4; mr 26,5; cmpw 28,27; beq 4f; addi 31,28,4; cmpw 31,27; beq 4f; 0:; lwz 0,0x0(26); addi 3,1,8; lwz 5,0x0(28); stw 0,0x8(1); lwz 29,0x0(31); mr 4,29; bl _s8039ED4C_0; cmpwi 3,0; beq 2f; addi 30,31,4; subf. 0,28,31; ble 1f; mr 5,0; subf 3,0,30; mr 4,28; bl _s8039ED4C_1; 1:; stw 29,0x0(28); b 3f; 2:; lwz 0,0x8(1); mr 4,29; mr 3,31; addi 5,1,16; stw 0,0x10(1); bl _s8039ED4C_2; addi 30,31,4; 3:; mr 31,30; cmpw 31,27; bne 0b; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8039ED4C_0();
extern "C" void _s8039ED4C_1();
extern "C" void _s8039ED4C_2();
extern "C" void f_8039ED4C() {}
