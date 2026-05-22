// 0x8032C598 AudioFrameCallback(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26576(13); cmpwi 0,0; beq 0f; bl _s8032C598_0; lwz 3,-26560(13); bl _s8032C598_1; lwz 3,-26556(13); bl _s8032C598_2; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032C598_0();
extern "C" void _s8032C598_1();
extern "C" void _s8032C598_2();
extern "C" void f_8032C598() {}
