// 0x80285908 AptArray::AptArray(int, (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 31,3; mr 30,4; mr 24,5; li 4,22; li 27,0; bl _s80285908_0; lis 9,-32703; mr 4,30; addi 9,9,8984; addi 3,31,12; stw 9,0x8(31); bl _s80285908_1; li 0,0; lis 9,-32704; stb 0,0x20(31); li 11,0; addi 9,9,16352; stw 30,0x2c(31); lwz 0,0x20(31); mr 4,30; stw 9,0x8(31); mr 3,31; rlwinm 0,0,0,10,7; stw 11,0x24(31); stw 0,0x20(31); stw 11,0x28(31); bl _s80285908_2; lwz 0,0x2c(31); cmpw 27,0; bge 2f; lis 25,-32704; lis 26,-32704; li 28,0; 0:; lwzx 29,28,24; addi 4,25,14924; addi 5,26,14964; li 6,284; lwz 9,0x8(29); lwz 11,0x24(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; lwzx 30,28,11; mtspr 8,0; blrl; cmpwi 30,0; beq 1f; lwz 9,0x8(30); addi 4,25,14924; addi 5,26,14964; li 6,285; lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; 1:; lwz 9,0x24(31); addi 27,27,1; stwx 29,28,9; addi 28,28,4; lwz 0,0x2c(31); cmpw 27,0; blt 0b; 2:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80285908_0();
extern "C" void _s80285908_1();
extern "C" void _s80285908_2();
extern "C" void f_80285908() {}
