// 0x80212390 InteractorModule::UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace(cXObject (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-21488(13); mr 31,3; li 4,0; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32697; lwz 30,0x5e94(9); lwz 3,0x4(30); cmpwi 3,0; beq 0f; li 4,0; bl _s80212390_0; 0:; cmpwi 31,0; beq 1f; lwz 3,0x0(31); li 4,11; bl _s80212390_1; b 2f; 1:; li 3,0; 2:; cmpwi 3,0; bne 3f; lwz 9,0x4(31); lha 3,0x420(9); lwz 0,0x424(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,1; beq 3f; lis 3,-32697; mr 4,31; addi 3,3,24012; bl _s80212390_2; cmpwi 3,0; beq 4f; 3:; mr 3,30; bl _s80212390_3; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80212390_0();
extern "C" void _s80212390_1();
extern "C" void _s80212390_2();
extern "C" void _s80212390_3();
extern "C" void f_80212390() {}
