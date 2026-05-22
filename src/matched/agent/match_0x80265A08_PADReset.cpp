// 0x80265A08 PADReset (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80265A08_0; lwz 4,-23160(13); li 8,0; lwz 5,-23168(13); mr 31,3; lwz 0,-23164(13); or 30,30,4; lwz 4,-23176(13); or 5,5,0; lwz 0,-27640(13); andc 30,30,5; lwz 6,-23180(13); or 5,4,30; lwz 4,-23156(13); not 7,30; stw 5,-23176(13); and 5,6,7; and 4,4,7; lwz 7,-23176(13); cmplwi 0,4; stw 8,-23160(13); and 3,7,6; stw 5,-23180(13); stw 4,-23156(13); bne 0f; lwz 0,-23172(13); or 0,0,30; stw 0,-23172(13); 0:; bl _s80265A08_1; lwz 0,-27652(13); cmpwi 0,32; bne 1f; lwz 5,-23176(13); cntlzw 0,5; stw 0,-27652(13); lwz 4,-27652(13); cmpwi 4,32; beq 1f; lis 0,-32768; srw 0,0,4; andc 0,5,0; mulli 4,4,12; stw 0,-23176(13); lis 3,-32694; addi 0,3,-16400; add 3,0,4; li 4,0; li 5,12; bl _s80265A08_2; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s80265A08_3; 1:; mr 3,31; bl _s80265A08_4; lwz 0,0x1c(1); li 3,1; lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80265A08_0();
extern "C" void _s80265A08_1();
extern "C" void _s80265A08_2();
extern "C" void _s80265A08_3();
extern "C" void _s80265A08_4();
extern "C" void f_80265A08() {}
