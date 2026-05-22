// 0x803C99BC TArray<ECharacterNode, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 28,4,-1; mr 29,3; cmpwi 4,0; beq 1f; addi 30,3,-4; addi 31,3,-180; 0:; mr 9,29; addi 30,30,184; lwz 4,0xb4(9); mr 3,30; addi 31,31,184; addi 29,29,184; bl _s803C99BC_0; mr 3,31; li 4,2; bl _s803C99BC_1; cmpwi 28,0; addi 28,28,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803C99BC_0();
extern "C" void _s803C99BC_1();
extern "C" void f_803C99BC() {}
