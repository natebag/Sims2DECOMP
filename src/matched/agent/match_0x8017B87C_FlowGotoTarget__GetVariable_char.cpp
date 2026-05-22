// 0x8017B87C FlowGotoTarget::GetVariable(char (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,32; bl _s8017B87C_0; mr 31,3; li 0,0; lis 3,-32706; stb 0,0x0(31); addi 3,3,11640; mr 4,30; bl _s8017B87C_1; cmpwi 3,0; bne 0f; lis 9,-32706; addi 11,9,12504; lwz 10,0x30d8(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 2f; 0:; lis 3,-32706; mr 4,30; addi 3,3,12512; bl _s8017B87C_2; cmpwi 3,0; bne 1f; lis 4,-32706; lwz 5,0x84(29); addi 4,4,12532; mr 3,31; crxor 6,6,6; bl _s8017B87C_3; b 2f; 1:; lis 3,-32706; mr 4,30; addi 3,3,12536; bl _s8017B87C_4; cmpwi 3,0; bne 2f; lis 4,-32706; lwz 5,0x88(29); addi 4,4,12532; mr 3,31; crxor 6,6,6; bl _s8017B87C_5; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8017B87C_0();
extern "C" void _s8017B87C_1();
extern "C" void _s8017B87C_2();
extern "C" void _s8017B87C_3();
extern "C" void _s8017B87C_4();
extern "C" void _s8017B87C_5();
extern "C" void f_8017B87C() {}
