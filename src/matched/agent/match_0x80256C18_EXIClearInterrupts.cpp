// 0x80256C18 EXIClearInterrupts (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 0,3,20; lis 3,-13312; addi 7,3,26624; add 7,7,0; lwz 0,0x0(7); mr 3,0; andi. 0,0,2037; cmpwi 4,0; beq 0f; ori 0,0,2; 0:; cmpwi 5,0; beq 1f; ori 0,0,8; 1:; cmpwi 6,0; beq 2f; ori 0,0,2048; 2:; stw 0,0x0(7)"
extern "C" void f_80256C18() {}
