// 0x80287E58 AptArray::SetAt(int, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,5; mr 28,3; lwz 9,0x8(30); rlwinm 29,4,2,0,29; lis 27,-32704; lis 26,-32704; lha 3,0x8(9); addi 4,27,14924; lwz 0,0xc(9); addi 5,26,14964; add 3,30,3; li 6,284; mtspr 8,0; lwz 9,0x24(28); lwzx 31,29,9; blrl; cmpwi 31,0; beq 0f; lwz 9,0x8(31); addi 4,27,14924; addi 5,26,14964; li 6,285; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 9,0x24(28); stwx 30,29,9; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_80287E58() {}
