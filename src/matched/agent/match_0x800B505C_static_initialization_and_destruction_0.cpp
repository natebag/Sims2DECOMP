// 0x800B505C __static_initialization_and_destruction_0 (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 0f; lis 30,-32696; li 4,0; addi 30,30,24096; li 5,-1; mr 3,30; li 6,0; bl _s800B505C_0; addi 30,30,3; mr 3,30; li 4,0; li 5,1; li 6,0; bl _s800B505C_1; addi 30,30,3; mr 3,30; li 4,-1; li 5,0; li 6,0; bl _s800B505C_2; addi 30,30,3; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s800B505C_3; addi 30,30,3; mr 3,30; li 4,-1; li 5,-1; li 6,0; bl _s800B505C_4; addi 30,30,3; mr 3,30; li 4,1; li 5,1; li 6,0; bl _s800B505C_5; addi 30,30,3; li 4,1; li 5,-1; li 6,0; mr 3,30; bl _s800B505C_6; addi 3,30,3; li 4,-1; li 5,1; li 6,0; bl _s800B505C_7; b 2f; 0:; lis 9,-32696; addi 9,9,24096; cmpwi 9,0; beq 2f; addi 30,9,24; cmpw 30,9; beq 2f; mr 31,9; 1:; addi 30,30,-3; li 4,0; mr 3,30; bl _s800B505C_8; cmpw 30,31; bne 1b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B505C_0();
extern "C" void _s800B505C_1();
extern "C" void _s800B505C_2();
extern "C" void _s800B505C_3();
extern "C" void _s800B505C_4();
extern "C" void _s800B505C_5();
extern "C" void _s800B505C_6();
extern "C" void _s800B505C_7();
extern "C" void _s800B505C_8();
extern "C" void f_800B505C() {}
