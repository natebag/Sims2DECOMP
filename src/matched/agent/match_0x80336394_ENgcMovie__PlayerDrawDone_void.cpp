// 0x80336394 ENgcMovie::PlayerDrawDone(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80336394_0; lwz 0,0x20(30); cmpwi 0,0; beq 2f; b 1f; 0:; bl _s80336394_1; 1:; bl _s80336394_2; mr. 3,3; bne 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80336394_0();
extern "C" void _s80336394_1();
extern "C" void _s80336394_2();
extern "C" void f_80336394() {}
