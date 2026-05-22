// 0x800AB7B4 Behavior::IsNodeReachable(short, (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); li 0,0; mr 30,5; stw 0,0x8(1); addi 5,1,8; li 6,1; bl _s800AB7B4_0; cmpwi 3,0; beq 4f; cmpwi 30,0; blt 4f; lwz 3,0x8(1); bl _s800AB7B4_1; cmpw 30,3; bge 4f; lwz 3,0x8(1); li 31,0; bl _s800AB7B4_2; mr 29,3; cmpw 31,29; bge 4f; 0:; cmpw 31,30; beq 3f; lwz 3,0x8(1); mr 4,31; bl _s800AB7B4_3; lbz 0,0x2(3); cmpw 0,30; beq 1f; lwz 3,0x8(1); mr 4,31; bl _s800AB7B4_4; lbz 0,0x3(3); cmpw 0,30; bne 3f; 1:; lwz 11,0x8(1); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 3,1; b 6f; 3:; addi 31,31,1; cmpw 31,29; blt 0b; 4:; lwz 11,0x8(1); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 5:; li 3,0; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800AB7B4_0();
extern "C" void _s800AB7B4_1();
extern "C" void _s800AB7B4_2();
extern "C" void _s800AB7B4_3();
extern "C" void _s800AB7B4_4();
extern "C" void f_800AB7B4() {}
