// 0x80335F10 ENgcMovie::PlayerPlay(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32691; addi 8,9,14656; lwz 0,0xa0(8); cmpwi 0,0; beq 1f; lbz 0,0xa4(8); cmpwi 0,1; beq 0f; cmpwi 0,4; bne 1f; 0:; li 9,-1; li 11,0; li 0,2; li 10,-1; stb 0,0xa4(8); li 3,1; stw 9,0xc8(8); stw 10,0xcc(8); stw 11,0xd4(8); stw 11,0xd0(8); blr; 1:; li 3,0"
extern "C" void f_80335F10() {}
