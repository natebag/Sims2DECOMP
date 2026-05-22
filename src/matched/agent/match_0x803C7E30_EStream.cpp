// 0x803C7E30 EStream (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 3,30; bl _s803C7E30_0; lwz 9,0x18(31); addi 4,1,8; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x8(1); mr 3,30; bl _s803C7E30_1; lwz 9,0x18(31); addi 4,1,12; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x18(31); addi 4,1,16; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; addi 4,1,20; mr 3,31; bl _s803C7E30_2; lwz 4,0x10(1); mr 3,30; lwz 5,0x14(1); li 6,1; bl _s803C7E30_3; 1:; lwz 9,0xc(1); addi 9,9,-1; cmpwi 9,-1; stw 9,0xc(1); bne 0b; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s803C7E30_0();
extern "C" void _s803C7E30_1();
extern "C" void _s803C7E30_2();
extern "C" void _s803C7E30_3();
extern "C" void f_803C7E30() {}
