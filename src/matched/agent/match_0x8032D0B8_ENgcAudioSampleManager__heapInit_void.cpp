// 0x8032D0B8 ENgcAudioSampleManager::heapInit(void) (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; lis 3,56; bl _s8032D0B8_0; lis 9,-32692; addis 11,3,28; addi 31,9,18184; addis 0,3,56; lwz 29,0x8(31); stw 0,-26540(13); stw 11,-26536(13); cmpwi 29,0; stw 3,-26544(13); bne 1f; bl _s8032D0B8_1; li 4,1284; li 5,0; bl _s8032D0B8_2; lwz 0,0x4(31); li 11,63; mtspr 9,11; addi 9,3,4; stw 0,0x0(3); stw 3,0x4(31); 0:; addi 11,9,20; stw 11,0x0(9); mr 9,11; bdnz 0b; lwz 9,0x8(31); addi 0,3,4; mr 29,0; stw 9,0x0(11); stw 0,0x8(31); 1:; lwz 9,0x8(31); lis 11,-32692; addi 30,11,18184; lwz 0,0x0(9); stw 0,0x8(31); stw 29,0xd20(27); lwz 31,0x8(30); cmpwi 31,0; bne 3f; bl _s8032D0B8_3; li 4,1284; li 5,0; bl _s8032D0B8_4; lwz 0,0x4(30); li 11,63; mtspr 9,11; addi 9,3,4; stw 0,0x0(3); stw 3,0x4(30); 2:; addi 11,9,20; stw 11,0x0(9); mr 9,11; bdnz 2b; lwz 9,0x8(30); addi 0,3,4; mr 31,0; stw 9,0x0(11); stw 0,0x8(30); 3:; lwz 9,0x8(30); lis 11,-32692; addi 28,11,18184; lwz 0,0x0(9); stw 0,0x8(30); stw 31,0xd24(27); lwz 6,0x8(28); cmpwi 6,0; bne 5f; bl _s8032D0B8_5; li 4,1284; li 5,0; bl _s8032D0B8_6; lwz 0,0x4(28); li 11,63; mtspr 9,11; addi 9,3,4; stw 0,0x0(3); stw 3,0x4(28); 4:; addi 11,9,20; stw 11,0x0(9); mr 9,11; bdnz 4b; lwz 9,0x8(28); addi 0,3,4; mr 6,0; stw 9,0x0(11); stw 0,0x8(28); 5:; lwz 11,0x8(28); li 0,0; lwz 8,-26544(13); li 10,-1; lwz 9,0x0(11); lwz 7,-26540(13); stw 9,0x8(28); stw 10,0x10(29); stw 0,0x0(29); stw 31,0x4(29); stw 0,0xc(29); stw 0,0x8(29); stw 29,0x0(31); stw 8,0x10(31); stw 6,0x4(31); stw 0,0xc(31); stw 0,0x8(31); stw 7,0x10(6); stw 31,0x0(6); stw 0,0x8(6); stw 0,0x4(6); stw 0,0xc(6); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8032D0B8_0();
extern "C" void _s8032D0B8_1();
extern "C" void _s8032D0B8_2();
extern "C" void _s8032D0B8_3();
extern "C" void _s8032D0B8_4();
extern "C" void _s8032D0B8_5();
extern "C" void _s8032D0B8_6();
extern "C" void f_8032D0B8() {}
