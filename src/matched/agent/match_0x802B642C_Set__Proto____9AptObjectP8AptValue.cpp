// 0x802B642C Set__Proto____9AptObjectP8AptValue (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 30,3,12; mr. 31,4; beq 0f; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,18772; lha 3,0x8(9); addi 5,5,18820; lwz 0,0xc(9); li 6,80; add 3,31,3; mtspr 8,0; blrl; 0:; lwz 11,0x8(30); cmpwi 11,0; beq 1f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,18772; lha 3,0x10(9); addi 5,5,18820; lwz 0,0x14(9); li 6,81; add 3,11,3; mtspr 8,0; blrl; 1:; stw 31,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802B642C() {}
