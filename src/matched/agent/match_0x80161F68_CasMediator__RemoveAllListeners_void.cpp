// 0x80161F68 CasMediator::RemoveAllListeners(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); li 0,0; mr 31,3; stw 0,0x8(1); lwz 9,0x4(31); lwz 0,0x8(9); stw 0,0x8(1); b 1f; 0:; lwz 3,0x10(9); li 4,0; lwz 9,0x4(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x8(1); bl _s80161F68_0; stw 3,0x8(1); 1:; lwz 11,0x4(31); li 30,1; lwz 9,0x8(1); cmpw 9,11; bne 2f; li 30,0; 2:; cmpwi 30,0; bne 0b; lwz 0,0x8(31); cmpwi 0,0; beq 3f; lwz 4,0x4(11); mr 3,31; bl _s80161F68_1; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 30,0x8(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80161F68_0();
extern "C" void _s80161F68_1();
extern "C" void f_80161F68() {}
