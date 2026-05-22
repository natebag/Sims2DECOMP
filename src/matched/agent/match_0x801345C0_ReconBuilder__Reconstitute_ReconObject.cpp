// 0x801345C0 ReconBuilder::Reconstitute(ReconObject (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 31,5; mr 30,3; lwz 29,0x4(31); mr 28,4; addi 4,1,56; mr 27,6; lwz 9,0x8(29); lwz 11,0x4(29); stw 9,0x38(1); lbz 0,0x0(29); stw 11,0x40(1); extsb 0,0; stw 0,0x3c(1); bl _s801345C0_0; addi 4,1,60; mr 3,30; bl _s801345C0_1; mr 3,30; addi 4,1,64; bl _s801345C0_2; lwz 9,0x0(28); lha 3,0x18(9); lwz 0,0x1c(9); add 3,28,3; mtspr 8,0; blrl; addi 4,29,12; cmpwi 31,0; li 5,0; beq 0f; lwz 5,0x0(31); 0:; lwz 0,0x3c(1); li 7,1; cmpwi 0,0; bne 1f; li 7,0; 1:; addi 3,1,8; li 6,0; bl _s801345C0_3; cmpwi 27,0; beq 2f; lwz 0,0x40(1); stw 0,0x0(27); 2:; lwz 9,0x0(28); addi 4,1,8; lwz 5,0x40(1); lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s801345C0_4; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"
extern "C" void _s801345C0_0();
extern "C" void _s801345C0_1();
extern "C" void _s801345C0_2();
extern "C" void _s801345C0_3();
extern "C" void _s801345C0_4();
extern "C" void f_801345C0() {}
