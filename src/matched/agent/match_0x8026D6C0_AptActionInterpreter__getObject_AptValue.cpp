// 0x8026D6C0 AptActionInterpreter::getObject(AptValue (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 10,-32700; mr 29,3; lhz 11,-6476(10); addi 8,10,-6476; stw 8,0x8(1); mr 30,4; addi 0,11,1; addi 31,1,8; sth 0,-6476(10); lwz 9,0x0(5); lhz 0,0x2(9); cmpwi 0,0; bne 1f; rlwinm 0,11,0,16,31; sth 11,-6476(10); cmpwi 0,0; bne 0f; lhz 5,0x4(8); mr 4,8; lwz 3,-23020(13); addi 5,5,9; bl _s8026D6C0_0; 0:; mr 3,29; b 5f; 1:; mr 3,29; mr 4,30; addi 6,1,16; mr 7,31; bl _s8026D6C0_1; lwz 3,0x10(1); cmpwi 3,0; beq 3f; mr 4,31; mr 5,30; bl _s8026D6C0_2; mr. 31,3; beq 3f; lwz 9,0x8(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D6C0_3; 2:; mr 3,31; b 5f; 3:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D6C0_4; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8026D6C0_0();
extern "C" void _s8026D6C0_1();
extern "C" void _s8026D6C0_2();
extern "C" void _s8026D6C0_3();
extern "C" void _s8026D6C0_4();
extern "C" void f_8026D6C0() {}
