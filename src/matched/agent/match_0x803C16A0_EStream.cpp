// 0x803C16A0 EStream (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 3,30; bl _s803C16A0_0; lwz 9,0x18(31); addi 4,1,8; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x18(31); addi 4,1,12; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; addi 4,1,16; mr 3,31; bl _s803C16A0_1; lwz 4,0xc(1); mr 3,30; bl _s803C16A0_2; lwz 0,0x10(1); stw 0,0x0(3); 1:; lwz 9,0x8(1); addi 9,9,-1; cmpwi 9,-1; stw 9,0x8(1); bne 0b; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s803C16A0_0();
extern "C" void _s803C16A0_1();
extern "C" void _s803C16A0_2();
extern "C" void f_803C16A0() {}
