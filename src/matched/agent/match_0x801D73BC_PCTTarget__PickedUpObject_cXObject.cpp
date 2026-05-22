// 0x801D73BC PCTTarget::PickedUpObject(cXObject (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,1; li 29,0; mr. 31,4; beq 1f; lwz 9,0x4(31); lha 3,0x460(9); lwz 0,0x464(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x4(31); lha 3,0x3c8(9); lwz 0,0x3cc(9); add 3,31,3; mtspr 8,0; blrl; mr 29,3; b 1f; 0:; li 28,0; 1:; lwz 3,0x214(30); cmpwi 3,0; beq 2f; mr 4,28; bl _s801D73BC_0; lwz 3,0x214(30); mr 4,29; bl _s801D73BC_1; 2:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801D73BC_0();
extern "C" void _s801D73BC_1();
extern "C" void f_801D73BC() {}
