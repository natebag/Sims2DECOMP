// 0x802727F4 AptActionInterpreter::urlDecode(char (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,4; mr 28,5; lwz 4,0x0(28); mr 27,6; mr 31,25; li 29,0; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802727F4_0; 0:; lis 30,-32700; addi 26,30,-6476; stw 26,0x0(28); lhz 9,-6476(30); addi 9,9,1; sth 9,-6476(30); lwz 4,0x0(27); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802727F4_1; 1:; stw 26,0x0(27); cmpwi 31,0; lhz 9,-6476(30); addi 9,9,1; sth 9,-6476(30); b 4f; 2:; cmpwi 9,61; bne 3f; mr 29,31; 3:; addic. 31,31,1; 4:; beq 5f; lbz 9,0x0(31); extsb 0,9; cmpwi 0,0; beq 5f; cmpwi 0,38; bne 2b; 5:; cmpwi 29,0; beq 6f; mr 4,25; mr 3,28; subf 5,4,29; bl _s802727F4_2; addi 29,29,1; mr 3,28; bl _s802727F4_3; mr 4,29; mr 3,27; subf 5,4,31; bl _s802727F4_4; mr 3,27; bl _s802727F4_5; lbz 0,0x0(31); cmpwi 0,38; bne 7f; addi 31,31,1; b 7f; 6:; li 31,0; 7:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802727F4_0();
extern "C" void _s802727F4_1();
extern "C" void _s802727F4_2();
extern "C" void _s802727F4_3();
extern "C" void _s802727F4_4();
extern "C" void _s802727F4_5();
extern "C" void f_802727F4() {}
