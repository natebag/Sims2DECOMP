// 0x8026AA58 _AptInternalRender(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-23008(13); cmpwi 3,0; beq 0f; bl _s8026AA58_0; bl _s8026AA58_1; lwz 3,-23008(13); li 5,0; lwz 4,-22920(13); addi 3,3,40; bl _s8026AA58_2; lhz 9,-27242(13); addi 9,9,-1; sth 9,-27242(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026AA58_0();
extern "C" void _s8026AA58_1();
extern "C" void _s8026AA58_2();
extern "C" void f_8026AA58() {}
