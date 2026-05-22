// 0x8025F704 DVDResume (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8025F704_0; li 4,0; stw 4,-23468(13); mr 31,3; lwz 0,-23464(13); cmpwi 0,0; beq 0f; stw 4,-23464(13); bl _s8025F704_1; 0:; mr 3,31; bl _s8025F704_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025F704_0();
extern "C" void _s8025F704_1();
extern "C" void _s8025F704_2();
extern "C" void f_8025F704() {}
