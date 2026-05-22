// 0x8026F6DC AptActionInterpreter::getName2(AptCIH (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,4; addi 30,1,8; mr 29,3; lis 4,-32704; addi 4,4,5608; mr 3,30; bl _s8026F6DC_0; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F6DC_1; 0:; lwz 4,0x8(1); stw 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F6DC_2; 1:; mr 3,29; mr 4,31; li 5,0; bl _s8026F6DC_3; lwz 9,0x0(31); lhz 0,0x2(9); cmpwi 0,0; bne 3f; lis 4,-32704; mr 3,30; addi 4,4,6544; bl _s8026F6DC_4; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F6DC_5; 2:; lwz 4,0x8(1); stw 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F6DC_6; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8026F6DC_0();
extern "C" void _s8026F6DC_1();
extern "C" void _s8026F6DC_2();
extern "C" void _s8026F6DC_3();
extern "C" void _s8026F6DC_4();
extern "C" void _s8026F6DC_5();
extern "C" void _s8026F6DC_6();
extern "C" void f_8026F6DC() {}
