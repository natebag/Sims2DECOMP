// 0x80066FC0 SAnimator2::updateRenderModels(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x160(9); lwz 9,0x164(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 7f; lwz 11,0x4(30); li 4,8; lwz 9,0x4(11); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x130(30); mr 31,3; cmpw 0,31; beq 7f; lwz 3,0x8(30); cmpwi 3,0; beq 0f; lwz 0,0x630(3); cmpwi 0,-1; bne 7f; bl _s80066FC0_0; cmpwi 3,0; bne 7f; 0:; cmpwi 31,2; bgt 1f; cmpwi 31,1; bge 4f; cmpwi 31,0; beq 2f; b 5f; 1:; cmpwi 31,3; beq 3f; cmpwi 31,10; bgt 5f; b 4f; 2:; mr 3,30; bl _s80066FC0_1; b 6f; 3:; mr 3,30; bl _s80066FC0_2; b 6f; 4:; mr 4,31; mr 3,30; bl _s80066FC0_3; mr 4,3; li 5,0; mr 3,30; li 6,1; bl _s80066FC0_4; b 6f; 5:; mr 3,30; bl _s80066FC0_5; 6:; cmpwi 3,0; beq 7f; stw 31,0x130(30); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80066FC0_0();
extern "C" void _s80066FC0_1();
extern "C" void _s80066FC0_2();
extern "C" void _s80066FC0_3();
extern "C" void _s80066FC0_4();
extern "C" void _s80066FC0_5();
extern "C" void f_80066FC0() {}
