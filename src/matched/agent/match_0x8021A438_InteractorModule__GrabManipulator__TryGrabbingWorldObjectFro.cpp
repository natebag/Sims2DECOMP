// 0x8021A438 InteractorModule::GrabManipulator::TryGrabbingWorldObjectFromId(short) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; addi 3,31,100; bl _s8021A438_0; cmpwi 3,0; beq 2f; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; lwz 4,0x64(31); mr 3,31; bl _s8021A438_1; 0:; mr 3,31; li 4,0; bl _s8021A438_2; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s8021A438_3; bl _s8021A438_4; stw 3,-31536(13); 1:; lwz 3,-31536(13); lis 4,26334; ori 4,4,56946; bl _s8021A438_5; lis 9,-32697; lwz 3,0x5bf8(9); cmpwi 3,0; beq 4f; lwz 4,0x64(31); bl _s8021A438_6; b 4f; 2:; lwz 0,-31536(13); cmpwi 0,0; bne 3f; li 3,120; bl _s8021A438_7; bl _s8021A438_8; stw 3,-31536(13); 3:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s8021A438_9; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021A438_0();
extern "C" void _s8021A438_1();
extern "C" void _s8021A438_2();
extern "C" void _s8021A438_3();
extern "C" void _s8021A438_4();
extern "C" void _s8021A438_5();
extern "C" void _s8021A438_6();
extern "C" void _s8021A438_7();
extern "C" void _s8021A438_8();
extern "C" void _s8021A438_9();
extern "C" void f_8021A438() {}
