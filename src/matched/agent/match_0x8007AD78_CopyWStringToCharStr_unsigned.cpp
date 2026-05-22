// 0x8007AD78 CopyWStringToCharStr(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lhz 0,0x0(9); li 3,0; cmpwi 0,0; beq 1f; addi 5,5,-1; cmplw 3,5; bge 1f; 0:; lbz 0,0x1(9); addi 3,3,1; stb 0,0x0(4); addi 4,4,1; lhzu 0,0x2(9); cmpwi 0,0; beq 1f; cmplw 3,5; blt 0b; 1:; li 0,0; stb 0,0x0(4)"
extern "C" void f_8007AD78() {}
