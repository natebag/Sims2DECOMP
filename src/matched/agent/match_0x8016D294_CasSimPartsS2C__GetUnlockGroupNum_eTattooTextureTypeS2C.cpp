// 0x8016D294 CasSimPartsS2C::GetUnlockGroupNum(eTattooTextureTypeS2C, (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-640(1); mfspr 0,8; stmw 29,0x274(1); stw 0,0x284(1); mr 30,3; mr 31,4; lwz 0,0x4(30); mr 29,5; li 3,0; cmpwi 0,0; beq 3f; mr 3,30; bl _s8016D294_0; cmplw 29,3; bge 2f; cmpwi 31,2; bgt 2f; cmpwi 31,0; blt 2f; mr 4,31; mr 3,30; addi 5,1,8; bl _s8016D294_1; cmplw 29,3; bge 2f; lwz 9,0x4(30); li 0,0; lwz 3,0x4(9); cmpwi 3,0; beq 0f; lwz 0,-4(3); 0:; addi 9,1,8; rlwinm 0,0,0,24,31; lbzx 5,9,29; cmplw 5,0; bge 2f; mulli 9,5,20; lis 11,-32706; lfd f12,0x1038(11); add 9,3,9; lfs f0,0x10(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 1f; fctiwz f0,f13; stfd f0,0x268(1); lwz 3,0x26c(1); b 3f; 1:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x268(1); lwz 3,0x26c(1); xoris 3,3,32768; b 3f; 2:; li 3,0; 3:; lwz 0,0x284(1); mtspr 8,0; lmw 29,0x274(1); addi 1,1,640"
extern "C" void _s8016D294_0();
extern "C" void _s8016D294_1();
extern "C" void f_8016D294() {}
