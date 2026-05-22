// 0x801800B0 cXObjectImpl::SyncObjectIsReady(signed (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-144(1); mfspr 0,8; stmw 27,0x7c(1); stw 0,0x94(1); addi 30,1,8; mr 29,3; mr 28,4; mr 27,5; li 4,0; li 5,64; mr 3,30; crxor 6,6,6; bl _s801800B0_0; mr 3,29; mr 5,28; mr 4,30; bl _s801800B0_1; lis 9,-32706; stw 30,0x6c(1); addi 9,9,15232; cmpwi 27,0; stw 9,0x68(1); beq 0f; lis 9,-32706; addi 9,9,15248; b 1f; 0:; lis 9,-32706; addi 9,9,15252; 1:; stw 9,0x70(1); addi 10,1,88; lwz 0,0x68(1); addi 9,1,104; lwz 29,0x8(9); addi 11,1,72; lwz 30,0x4(9); lis 4,-32706; stw 0,0x58(1); addi 4,4,15128; stw 29,0x8(10); mr 8,11; stw 30,0x4(10); li 5,0; lwz 3,-25136(13); li 6,0; lwz 0,0x58(1); li 7,3; stw 0,0x48(1); stw 30,0x4(11); stw 29,0x8(11); bl _s801800B0_2; li 3,1; lwz 0,0x94(1); mtspr 8,0; lmw 27,0x7c(1); addi 1,1,144; blr; stwu 1,-160(1); mfspr 0,8; stmw 26,0x88(1); stw 0,0xa4(1); mr 29,3; mr 26,5; lis 3,-32706; addi 3,3,15016; bl _s801800B0_3; cmpwi 3,0; bne 6f; lis 9,-32702; li 27,0; addi 30,9,18208; li 28,0; 2:; mr 31,30; addi 30,31,24; lwz 5,-24(30); cmpwi 5,69; bne 3f; li 28,1; b 4f; 3:; addi 4,1,8; mr 3,29; bl _s801800B0_4; addi 3,1,8; mr 4,26; bl _s801800B0_5; cmpwi 3,0; bne 4f; li 27,1; 4:; cmpwi 27,0; bne 5f; cmpwi 28,0; beq 2b; b 6f; 5:; lwz 4,0x0(31); mr 3,29; bl _s801800B0_6; cmpwi 3,-1; beq 6f; rlwinm 9,3,4,0,27; li 0,0; addi 9,9,132; stwx 0,29,9; add 9,29,9; stw 0,0xc(9); stw 0,0x4(9); stw 0,0x8(9); 6:; lwz 0,0xa4(1); mtspr 8,0; lmw 26,0x88(1); addi 1,1,160"
extern "C" void _s801800B0_0();
extern "C" void _s801800B0_1();
extern "C" void _s801800B0_2();
extern "C" void _s801800B0_3();
extern "C" void _s801800B0_4();
extern "C" void _s801800B0_5();
extern "C" void _s801800B0_6();
extern "C" void f_801800B0() {}
