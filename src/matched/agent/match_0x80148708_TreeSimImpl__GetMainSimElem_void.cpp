// 0x80148708 TreeSimImpl::GetMainSimElem(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 31,0; addi 3,29,12; bl _s80148708_0; addi 30,3,-1; b 1f; 0:; addi 31,31,1; 1:; cmpw 31,30; bgt 2f; lwz 3,0x0(29); extsh 4,31; lwz 9,0x18(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; bl _s80148708_1; cmpwi 3,-1; bne 0b; addi 30,31,-1; 2:; cmpwi 30,-1; beq 3f; lwz 3,0x0(29); extsh 4,30; lwz 9,0x18(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; b 4f; 3:; lwz 3,0x0(29); lwz 9,0x18(3); lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80148708_0();
extern "C" void _s80148708_1();
extern "C" void f_80148708() {}
