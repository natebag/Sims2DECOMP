// 0x8015C1F4 ObjectDataObjDefinition::LoadFromQDataByID(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; bl _s8015C1F4_0; lwz 11,-21508(13); mr 4,30; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x8(3); li 4,0; lwz 3,0x0(9); cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,2,0,29; mr 5,29; add 4,3,4; bl _s8015C1F4_1; lwz 4,0x0(3); mr 3,31; bl _s8015C1F4_2; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015C1F4_0();
extern "C" void _s8015C1F4_1();
extern "C" void _s8015C1F4_2();
extern "C" void f_8015C1F4() {}
