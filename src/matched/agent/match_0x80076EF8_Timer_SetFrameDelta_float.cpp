// 0x80076EF8 Timer_SetFrameDelta(float) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32707; stfs f1,-32200(13); lfs f0,0x5cf0(9); fcmpu 0,f1,f0; bne 0f; lfs f0,-24904(13); lwz 0,-24892(13); stfs f0,-24908(13); stw 0,-24896(13); 0:; bl _s80076EF8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80076EF8_0();
extern "C" void f_80076EF8() {}
