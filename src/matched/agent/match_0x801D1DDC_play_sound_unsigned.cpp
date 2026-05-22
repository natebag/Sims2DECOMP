// 0x801D1DDC play_sound(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-31536(13); mr 31,3; cmpwi 0,0; bne 0f; li 3,120; bl _s801D1DDC_0; bl _s801D1DDC_1; stw 3,-31536(13); 0:; lwz 3,-31536(13); cmpwi 3,0; bne 1f; li 3,0; b 2f; 1:; mr 4,31; bl _s801D1DDC_2; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801D1DDC_0();
extern "C" void _s801D1DDC_1();
extern "C" void _s801D1DDC_2();
extern "C" void f_801D1DDC() {}
