// 0x800BE310 IFFResFile2::ClearMap(StringBuffer (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 30,0x130(1); stw 0,0x13c(1); mr 30,3; mr 31,4; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,-47; bne 0f; addi 3,1,8; bl _s800BE310_0; addi 3,1,8; mr 4,31; bl _s800BE310_1; addi 4,1,8; li 5,0; mr 3,30; bl _s800BE310_2; mr 30,3; addi 3,1,8; bl _s800BE310_3; addi 3,1,8; li 4,2; bl _s800BE310_4; mr 3,30; 0:; lwz 0,0x13c(1); mtspr 8,0; lmw 30,0x130(1); addi 1,1,312"
extern "C" void _s800BE310_0();
extern "C" void _s800BE310_1();
extern "C" void _s800BE310_2();
extern "C" void _s800BE310_3();
extern "C" void _s800BE310_4();
extern "C" void f_800BE310() {}
