// 0x80042388 EGlobal::TogglePlayerCheat(int) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; cmpwi 4,10; bne 1f; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s80042388_0; bl _s80042388_1; stw 3,-31536(13); 0:; lis 4,16032; lwz 3,-31536(13); ori 4,4,37919; bl _s80042388_2; b 5f; 1:; lhz 0,0x9c(11); li 9,1; slw 9,9,4; mr 3,11; xor 0,0,9; sth 0,0x9c(11); bl _s80042388_3; lwz 0,-21492(13); cmpwi 0,0; beq 5f; cmpwi 3,0; beq 3f; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s80042388_4; bl _s80042388_5; stw 3,-31536(13); 2:; lis 4,-12703; lwz 3,-31536(13); ori 4,4,40498; bl _s80042388_6; b 5f; 3:; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s80042388_7; bl _s80042388_8; stw 3,-31536(13); 4:; lis 4,7321; lwz 3,-31536(13); ori 4,4,46876; bl _s80042388_9; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80042388_0();
extern "C" void _s80042388_1();
extern "C" void _s80042388_2();
extern "C" void _s80042388_3();
extern "C" void _s80042388_4();
extern "C" void _s80042388_5();
extern "C" void _s80042388_6();
extern "C" void _s80042388_7();
extern "C" void _s80042388_8();
extern "C" void _s80042388_9();
extern "C" void f_80042388() {}
