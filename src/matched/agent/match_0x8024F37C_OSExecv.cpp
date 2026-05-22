// 0x8024F37C OSExecv (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-88(1); stw 31,0x54(1); stw 30,0x50(1); mr 30,3; mr 31,4; bl _s8024F37C_0; li 3,0; bl _s8024F37C_1; bl _s8024F37C_2; lis 3,-32472; bl _s8024F37C_3; lis 3,-32465; bl _s8024F37C_4; lbz 0,0x0(30); extsb 0,0; cmpwi 0,0; bne 0f; li 3,0; b 1f; 0:; mr 3,30; addi 4,1,16; bl _s8024F37C_5; cmpwi 3,0; beq 2f; lwz 3,0x40(1); 1:; mr 5,31; lis 4,-16384; bl _s8024F37C_6; 2:; lwz 0,0x5c(1); lwz 31,0x54(1); lwz 30,0x50(1); addi 1,1,88; mtspr 8,0"
extern "C" void _s8024F37C_0();
extern "C" void _s8024F37C_1();
extern "C" void _s8024F37C_2();
extern "C" void _s8024F37C_3();
extern "C" void _s8024F37C_4();
extern "C" void _s8024F37C_5();
extern "C" void _s8024F37C_6();
extern "C" void f_8024F37C() {}
