// 0x80336018 ENgcMovie::PlayerPause(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32691; addi 9,9,14656; lwz 0,0xa0(9); cmpwi 0,0; beq 0f; lbz 0,0xa4(9); cmpwi 0,2; bne 0f; li 0,4; li 3,1; stb 0,0xa4(9); stb 0,0xa5(9); blr; 0:; li 3,0"
extern "C" void f_80336018() {}
