// 0x800417DC EGlobal::CreateThumbnail(ObjSelector (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,-21484(13); mr 3,4; lwz 30,0x0(29); lha 0,0xe8(30); addi 30,30,232; add 29,29,0; bl _s800417DC_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 9,0x0(3); lwz 11,0x0(9); lwz 3,0x14(11); cmpwi 3,0; beq 0f; bl _s800417DC_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800417DC_0();
extern "C" void _s800417DC_1();
extern "C" void f_800417DC() {}
