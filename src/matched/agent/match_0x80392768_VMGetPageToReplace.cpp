// 0x80392768 __VMGetPageToReplace (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,-25212(13); cmpwi 0,0; bne 0f; bl _s80392768_0; b 2f; 0:; cmpwi 0,1; bne 1f; bl _s80392768_1; b 2f; 1:; bl _s80392768_2; 2:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392768_0();
extern "C" void _s80392768_1();
extern "C" void _s80392768_2();
extern "C" void f_80392768() {}
