// 0x80375988 ARInit (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; lwz 0,-22340(13); cmpwi 0,1; bne 0f; li 3,16384; b 1f; 0:; lwz 3,-25384(13); bl _s80375988_0; bl _s80375988_1; li 0,0; lis 4,-32713; stw 0,-22368(13); addi 31,3,0; addi 4,4,23300; li 3,6; bl _s80375988_2; lis 3,512; bl _s80375988_3; li 0,16384; stw 30,-22348(13); lis 3,-13312; stw 0,-22352(13); addi 4,3,20480; stw 29,-22344(13); lhz 0,0x1a(4); lhz 3,0x501a(3); rlwinm 0,0,0,0,23; rlwimi 0,3,0,24,31; sth 0,0x1a(4); bl _s80375988_4; li 0,1; stw 0,-22340(13); mr 3,31; bl _s80375988_5; lwz 3,-22352(13); 1:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80375988_0();
extern "C" void _s80375988_1();
extern "C" void _s80375988_2();
extern "C" void _s80375988_3();
extern "C" void _s80375988_4();
extern "C" void _s80375988_5();
extern "C" void f_80375988() {}
