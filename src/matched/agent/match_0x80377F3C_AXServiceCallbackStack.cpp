// 0x80377F3C __AXServiceCallbackStack (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80377F3C_0; mr 31,3; b 3f; 0:; lwz 0,0xc(31); cmplwi 0,0; beq 2f; lwz 12,0x10(31); cmplwi 12,0; beq 1f; mtspr 8,12; addi 3,31,0; blrl; 1:; mr 3,31; bl _s80377F3C_1; mr 3,31; bl _s80377F3C_2; 2:; bl _s80377F3C_3; mr 31,3; 3:; cmplwi 31,0; bne 0b; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80377F3C_0();
extern "C" void _s80377F3C_1();
extern "C" void _s80377F3C_2();
extern "C" void _s80377F3C_3();
extern "C" void f_80377F3C() {}
