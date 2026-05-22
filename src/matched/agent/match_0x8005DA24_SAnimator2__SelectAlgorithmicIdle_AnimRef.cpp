// 0x8005DA24 SAnimator2::SelectAlgorithmicIdle(AnimRef (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 4,0x28(31); li 28,-1; cmpwi 4,0; beq 1f; lis 30,-32693; addi 3,30,11064; bl _s8005DA24_0; cmpwi 3,0; bne 0f; li 3,0; li 4,2; b 10f; 0:; lwz 4,0x28(31); addi 3,30,11064; li 5,1; bl _s8005DA24_1; lis 3,-32707; lwz 4,0x28(31); addi 3,3,17872; crxor 6,6,6; bl _s8005DA24_2; lwz 9,-32344(13); li 0,0; stw 0,0x28(31); addi 9,9,-1; stw 9,-32344(13); 1:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; stw 3,0x124(31); beq 4f; bgt 2f; cmpwi 3,-1; beq 7f; cmpwi 3,0; beq 3f; b 7f; 2:; cmpwi 3,2; beq 5f; cmpwi 3,3; bne 7f; 3:; mr 3,31; bl _s8005DA24_3; lis 9,-32707; mr 28,3; b 6f; 4:; lis 9,-32707; li 28,1; b 6f; 5:; lis 9,-32707; li 28,2; 6:; lfs f0,0x45e8(9); stfs f0,0x128(31); 7:; cmpwi 28,-1; bne 8f; li 3,0; li 4,0; b 10f; 8:; lbz 0,0x5fa(31); cmpwi 0,0; bne 9f; lwz 3,0x4(31); mr 4,28; mr 5,29; bl _s8005DA24_4; lwz 4,0x0(29); mr 3,31; bl _s8005DA24_5; b 10f; 9:; mr 3,31; bl _s8005DA24_6; stw 3,0x0(29); li 3,0; lwz 0,0x61c(31); li 4,1; andis. 9,0,16; beq 10f; li 3,0; li 4,2; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8005DA24_0();
extern "C" void _s8005DA24_1();
extern "C" void _s8005DA24_2();
extern "C" void _s8005DA24_3();
extern "C" void _s8005DA24_4();
extern "C" void _s8005DA24_5();
extern "C" void _s8005DA24_6();
extern "C" void f_8005DA24() {}
