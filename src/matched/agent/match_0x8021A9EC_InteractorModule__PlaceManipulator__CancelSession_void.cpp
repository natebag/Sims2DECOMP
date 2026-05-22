// 0x8021A9EC InteractorModule::PlaceManipulator::CancelSession(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); lis 9,-32697; addi 30,1,8; addi 9,9,-31728; li 0,0; stw 9,0x8(30); li 11,3; stw 0,0xc(30); mr 31,3; stw 11,0x8(1); mr 3,30; addi 11,31,172; lis 9,-32697; lwz 0,0x8(11); addi 27,9,-32168; addi 28,31,100; li 29,0; stw 0,0x4(30); lwz 0,0xc(11); mtspr 8,0; blrl; lwz 11,0x64(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lwz 0,0x424(9); lha 3,0x420(9); mtspr 8,0; add 3,11,3; blrl; xori 29,3,1; subfic 0,29,0; adde 29,0,29; 0:; mr 3,28; bl _s8021A9EC_0; cmpwi 29,0; beq 1f; li 3,0; bl _s8021A9EC_1; 1:; mr 3,31; li 4,1; bl _s8021A9EC_2; stw 27,0x8(30); lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s8021A9EC_0();
extern "C" void _s8021A9EC_1();
extern "C" void _s8021A9EC_2();
extern "C" void f_8021A9EC() {}
