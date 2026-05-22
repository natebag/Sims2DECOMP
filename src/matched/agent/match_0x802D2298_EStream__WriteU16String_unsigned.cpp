// 0x802D2298 EStream::WriteU16String(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lhz 0,0x0(4); mr 30,3; li 29,0; cmpwi 0,0; beq 1f; mr 31,4; 0:; lwz 9,0x18(30); addi 4,1,8; li 5,2; lhz 0,0x0(31); lha 3,0x38(9); addi 29,29,1; lwz 9,0x3c(9); add 3,30,3; sth 0,0x8(1); mtspr 8,9; blrl; lhzu 0,0x2(31); cmpwi 0,0; bne 0b; 1:; lwz 9,0x18(30); addi 4,1,8; li 5,2; li 0,0; lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; sth 0,0x8(1); mtspr 8,9; blrl; addi 3,29,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void f_802D2298() {}
