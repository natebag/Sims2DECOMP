// 0x80285FEC AptArray::set(int, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; mr 29,5; mr. 31,4; blt 2f; addi 28,31,1; mr 4,28; lis 25,-32704; bl _s80285FEC_0; lis 26,-32704; lwz 9,0x8(29); addi 4,25,14924; addi 5,26,14964; li 6,284; lha 3,0x8(9); rlwinm 27,31,2,0,29; lwz 0,0xc(9); add 3,29,3; lwz 9,0x24(30); mtspr 8,0; lwzx 31,27,9; blrl; cmpwi 31,0; beq 0f; lwz 9,0x8(31); addi 4,25,14924; addi 5,26,14964; li 6,285; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 9,0x24(30); stwx 29,27,9; lwz 0,0x2c(30); cmpw 0,28; bge 1f; mr 0,28; 1:; stw 0,0x2c(30); 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80285FEC_0();
extern "C" void f_80285FEC() {}
