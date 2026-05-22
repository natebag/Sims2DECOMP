// 0x803B5114 _String_base<wchar_t, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 4,4; blt 2f; cmpwi 4,0; beq 2f; add 0,4,4; mr 31,0; cmplwi 0,128; ble 0f; mr 3,31; bl _s803B5114_0; b 1f; 0:; mr 3,31; bl _s803B5114_1; 1:; add 0,3,31; stw 3,0x0(30); stw 0,0xc(30); stw 3,0x4(30); b 3f; 2:; mr 3,30; bl _s803B5114_2; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803B5114_0();
extern "C" void _s803B5114_1();
extern "C" void _s803B5114_2();
extern "C" void f_803B5114() {}
