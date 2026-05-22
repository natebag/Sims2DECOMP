// 0x8025C2A4 DVDInit (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); stw 30,0x8(1); lwz 0,-23404(13); cmpwi 0,0; bne 1f; lwz 3,-27792(13); bl _s8025C2A4_0; li 30,1; stw 30,-23404(13); bl _s8025C2A4_1; bl _s8025C2A4_2; bl _s8025C2A4_3; lis 0,-32768; li 31,0; stw 0,-23472(13); lis 3,-32730; addi 4,3,3168; stw 31,-23408(13); li 3,21; stw 0,-23476(13); bl _s8025C2A4_4; li 3,1024; bl _s8025C2A4_5; addi 3,13,-23488; bl _s8025C2A4_6; lis 3,-13312; li 0,42; stw 0,0x6000(3); stw 31,0x6004(3); lwz 3,-23472(13); addi 3,3,32; lwz 3,0x0(3); addis 0,3,6880; cmplwi 0,31778; bne 0f; lis 3,-32700; crxor 6,6,6; addi 3,3,-14504; bl _s8025C2A4_7; bl _s8025C2A4_8; b 1f; 0:; addis 0,3,-3349; cmplwi 0,59998; beq 1f; stw 30,-23412(13); 1:; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025C2A4_0();
extern "C" void _s8025C2A4_1();
extern "C" void _s8025C2A4_2();
extern "C" void _s8025C2A4_3();
extern "C" void _s8025C2A4_4();
extern "C" void _s8025C2A4_5();
extern "C" void _s8025C2A4_6();
extern "C" void _s8025C2A4_7();
extern "C" void _s8025C2A4_8();
extern "C" void f_8025C2A4() {}
