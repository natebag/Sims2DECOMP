// 0x8032B8EC ENgcAudio::InitAudio(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-26576(13); mr 31,3; cmpwi 0,0; beq 5f; lwz 0,-26572(13); cmpwi 0,0; bne 5f; li 3,0; bl _s8032B8EC_0; bl _s8032B8EC_1; bl _s8032B8EC_2; lis 3,-32717; addi 3,3,-14952; bl _s8032B8EC_3; li 3,2; bl _s8032B8EC_4; bl _s8032B8EC_5; cmpwi 3,0; bne 0f; li 3,0; bl _s8032B8EC_6; b 1f; 0:; li 3,3; bl _s8032B8EC_7; 1:; lwz 0,-26556(13); cmpwi 0,0; bne 2f; li 3,1; bl _s8032B8EC_8; bl _s8032B8EC_9; stw 3,-26556(13); 2:; lwz 0,-26560(13); cmpwi 0,0; bne 3f; li 3,1; bl _s8032B8EC_10; bl _s8032B8EC_11; stw 3,-26560(13); 3:; li 10,64; lis 11,-32692; mtspr 9,10; lis 9,-32692; addi 9,9,14048; addi 11,11,9696; li 0,-1; 4:; stw 0,0x0(11); stw 0,0x40(11); stw 0,0x4(11); stw 0,0x0(9); addi 11,11,68; addi 9,9,4; bdnz 4b; li 0,0; li 9,1; stw 0,0xc(31); stw 9,-26572(13); 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8032B8EC_0();
extern "C" void _s8032B8EC_1();
extern "C" void _s8032B8EC_2();
extern "C" void _s8032B8EC_3();
extern "C" void _s8032B8EC_4();
extern "C" void _s8032B8EC_5();
extern "C" void _s8032B8EC_6();
extern "C" void _s8032B8EC_7();
extern "C" void _s8032B8EC_8();
extern "C" void _s8032B8EC_9();
extern "C" void _s8032B8EC_10();
extern "C" void _s8032B8EC_11();
extern "C" void f_8032B8EC() {}
