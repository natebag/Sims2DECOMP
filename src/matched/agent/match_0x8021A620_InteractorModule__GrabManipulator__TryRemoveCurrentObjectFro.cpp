// 0x8021A620 InteractorModule::GrabManipulator::TryRemoveCurrentObjectFromWorld(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; addi 30,31,100; mr 3,30; bl _s8021A620_0; cmpwi 3,0; beq 6f; lis 9,-32697; lwz 0,0x64(31); addi 11,1,8; addi 9,9,-31496; stw 9,0x8(11); li 10,0; li 8,2; stw 0,0x14(1); stw 10,0x18(1); addi 9,31,172; stw 8,0x8(1); mr 3,11; mr 28,11; lwz 0,0x8(9); stw 0,0x4(11); lwz 0,0xc(9); mtspr 8,0; blrl; lwz 0,0x18(1); cmpwi 0,0; beq 3f; lwz 11,0x64(31); li 29,0; cmpwi 11,0; beq 0f; lwz 9,0x4(11); lwz 0,0x424(9); lha 3,0x420(9); mtspr 8,0; add 3,11,3; blrl; xori 29,3,1; subfic 0,29,0; adde 29,0,29; 0:; mr 3,30; bl _s8021A620_1; mr 3,31; li 4,1; bl _s8021A620_2; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 1f; mr 3,31; li 4,0; bl _s8021A620_3; 1:; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s8021A620_4; bl _s8021A620_5; stw 3,-31536(13); 2:; lwz 3,-31536(13); lis 4,26334; ori 4,4,56946; bl _s8021A620_6; cmpwi 29,0; beq 5f; li 3,0; bl _s8021A620_7; b 5f; 3:; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s8021A620_8; bl _s8021A620_9; stw 3,-31536(13); 4:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s8021A620_10; 5:; lis 9,-32697; addi 9,9,-32168; stw 9,0x8(28); b 8f; 6:; lwz 0,-31536(13); cmpwi 0,0; bne 7f; li 3,120; bl _s8021A620_11; bl _s8021A620_12; stw 3,-31536(13); 7:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s8021A620_13; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s8021A620_0();
extern "C" void _s8021A620_1();
extern "C" void _s8021A620_2();
extern "C" void _s8021A620_3();
extern "C" void _s8021A620_4();
extern "C" void _s8021A620_5();
extern "C" void _s8021A620_6();
extern "C" void _s8021A620_7();
extern "C" void _s8021A620_8();
extern "C" void _s8021A620_9();
extern "C" void _s8021A620_10();
extern "C" void _s8021A620_11();
extern "C" void _s8021A620_12();
extern "C" void _s8021A620_13();
extern "C" void f_8021A620() {}
