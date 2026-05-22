// 0x80329460 ImageProcessingManager::Close(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-26588(13); cmpwi 3,0; beq 0f; bl _s80329460_0; li 0,0; stw 0,-26588(13); 0:; li 0,0; stw 0,-26584(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80329460_0();
extern "C" void f_80329460() {}
