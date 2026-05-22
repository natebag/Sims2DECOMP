// 0x8021A8D8 InteractorModule::PlaceManipulator::TryPlacingCurrentObject(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 30,3; lwz 31,0x64(30); cmpwi 31,0; beq 0f; lwz 9,0x4(31); li 4,1; lha 3,0x260(9); lwz 0,0x264(9); add 3,31,3; mtspr 8,0; blrl; mr 28,3; b 1f; 0:; li 28,0; 1:; addi 3,30,100; bl _s8021A8D8_0; mr 29,3; cmpwi 29,1; bne 5f; cmpwi 31,0; beq 2f; lwz 9,0x4(31); li 4,1; lha 3,0x468(9); lwz 0,0x46c(9); add 3,31,3; mtspr 8,0; blrl; 2:; lis 9,-32697; lwz 0,0xc0(30); addi 11,1,8; addi 9,9,-31728; li 10,0; stw 9,0x8(11); stw 10,0xc(11); addi 31,30,172; stw 0,0x18(1); mr 3,11; stw 10,0x8(1); mr 27,11; lwz 0,0x8(31); stw 0,0x4(11); lwz 9,0xc(31); mtspr 8,9; blrl; lwz 0,0x14(1); cmpwi 0,0; beq 3f; stw 29,0xc8(30); mr 3,30; sth 28,0xcc(30); mr 4,31; bl _s8021A8D8_1; b 4f; 3:; mr 3,30; li 4,1; bl _s8021A8D8_2; 4:; lis 9,-32697; addi 9,9,-32168; stw 9,0x8(27); 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s8021A8D8_0();
extern "C" void _s8021A8D8_1();
extern "C" void _s8021A8D8_2();
extern "C" void f_8021A8D8() {}
