// 0x80212128 InteractorModule::IsLegalToPlaceAtLocation(cXObject (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,5; mr. 31,3; beq 0f; lwz 9,0x4(31); lha 3,0x1a8(9); lwz 0,0x1ac(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; 0:; li 3,0; b 3f; 1:; lwz 9,0x4(31); lha 3,0x390(9); lwz 0,0x394(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; mr 4,30; mr 5,29; bl _s80212128_0; b 3f; 2:; mr 3,31; mr 4,30; bl _s80212128_1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80212128_0();
extern "C" void _s80212128_1();
extern "C" void f_80212128() {}
