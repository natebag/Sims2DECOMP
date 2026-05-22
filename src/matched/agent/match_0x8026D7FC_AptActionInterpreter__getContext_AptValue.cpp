// 0x8026D7FC AptActionInterpreter::getContext(AptValue (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-288(1); mfspr 0,8; stmw 28,0x110(1); stw 0,0x124(1); mr 31,5; mr 28,3; lwz 9,0x0(31); mr 29,6; mr 30,7; li 11,1; addi 9,9,8; 0:; lbz 0,0x0(9); addi 9,9,1; extsb 0,0; cmpwi 0,0; beq 2f; cmpwi 0,47; ble 1f; cmpwi 0,58; bne 0b; 1:; li 11,0; 2:; cmpwi 11,0; beq 4f; cmpwi 4,0; bne 4f; lwz 11,0x0(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D7FC_0; 3:; lwz 0,0x0(31); li 3,0; stw 0,0x0(30); stw 28,0x0(29); b 7f; 4:; mr 5,31; mr 6,29; addi 7,1,8; mr 3,28; bl _s8026D7FC_1; mr 31,3; addi 4,1,8; addi 3,1,264; bl _s8026D7FC_2; lwz 11,0x108(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D7FC_3; 5:; lwz 4,0x108(1); stw 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D7FC_4; 6:; mr 3,31; 7:; lwz 0,0x124(1); mtspr 8,0; lmw 28,0x110(1); addi 1,1,288"
extern "C" void _s8026D7FC_0();
extern "C" void _s8026D7FC_1();
extern "C" void _s8026D7FC_2();
extern "C" void _s8026D7FC_3();
extern "C" void _s8026D7FC_4();
extern "C" void f_8026D7FC() {}
