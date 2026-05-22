// 0x8004AD24 BBI::InventoryItems::DoStreamWrite(ReconBuffer (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 31,3; mr 29,4; mr 26,5; bl _s8004AD24_0; li 28,0; mr 27,3; cmplw 28,27; bge 3f; mr 30,31; li 25,1; 0:; lwz 31,0x0(30); addi 30,30,4; cmpwi 31,0; beq 1f; mr 3,29; addi 4,1,8; li 5,1; stb 25,0x8(1); bl _s8004AD24_1; lwz 9,0x8(31); mr 4,29; mr 5,26; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; b 2f; 1:; stb 31,0x8(1); mr 3,29; addi 4,1,8; li 5,1; bl _s8004AD24_2; 2:; addi 28,28,1; cmplw 28,27; blt 0b; 3:; li 3,1; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8004AD24_0();
extern "C" void _s8004AD24_1();
extern "C" void _s8004AD24_2();
extern "C" void f_8004AD24() {}
