// 0x8039FB78 _Rb_global<bool>::_Rebalance(_Rb_tree_node_base (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 0,0; stw 0,0x0(31); mr 30,4; lwz 0,0x0(30); cmpw 31,0; beq 8f; lwz 10,0x4(31); lwz 0,0x0(10); cmpwi 0,0; bne 8f; li 29,1; li 28,0; 0:; lwz 11,0x4(10); lwz 9,0x8(11); cmpw 10,9; bne 3f; lwz 9,0xc(11); cmpwi 9,0; beq 1f; lwz 0,0x0(9); cmpwi 0,0; beq 4f; 1:; lwz 9,0x4(31); lwz 0,0xc(9); cmpw 31,0; bne 2f; mr 31,9; mr 4,30; mr 3,31; bl _s8039FB78_0; 2:; lwz 11,0x4(31); mr 4,30; stw 29,0x0(11); lwz 9,0x4(31); lwz 11,0x4(9); stw 28,0x0(11); lwz 9,0x4(31); lwz 3,0x4(9); bl _s8039FB78_1; b 7f; 3:; cmpwi 9,0; beq 5f; lwz 0,0x0(9); cmpwi 0,0; bne 5f; 4:; stw 29,0x0(10); stw 29,0x0(9); lwz 9,0x4(31); lwz 11,0x4(9); stw 0,0x0(11); lwz 9,0x4(31); lwz 31,0x4(9); b 7f; 5:; lwz 9,0x4(31); lwz 0,0x8(9); cmpw 31,0; bne 6f; mr 31,9; mr 4,30; mr 3,31; bl _s8039FB78_2; 6:; lwz 11,0x4(31); mr 4,30; stw 29,0x0(11); lwz 9,0x4(31); lwz 11,0x4(9); stw 28,0x0(11); lwz 9,0x4(31); lwz 3,0x4(9); bl _s8039FB78_3; 7:; lwz 0,0x0(30); cmpw 31,0; beq 8f; lwz 10,0x4(31); lwz 0,0x0(10); cmpwi 0,0; beq 0b; 8:; lwz 9,0x0(30); li 0,1; stw 0,0x0(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8039FB78_0();
extern "C" void _s8039FB78_1();
extern "C" void _s8039FB78_2();
extern "C" void _s8039FB78_3();
extern "C" void f_8039FB78() {}
