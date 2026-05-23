// 0x80068680 SAnimator2::GetFootSound(CTilePt (884 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); addi 30,1,8; mr 27,3; mr 3,30; mr 4,27; li 5,0; mr 28,30; bl _s80068680_0; li 31,9999; lwz 0,0x4(30); li 29,-1; cmpwi 0,0; beq 13f; 0:; lwz 30,0x4(28); lwz 9,0x4(30); lha 3,0x2d0(9); lwz 0,0x2d4(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 12f; lwz 9,0x4(30); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,30,3; blrl; bl _s80068680_1; lis 0,20841; ori 0,0,24645; cmpw 3,0; beq 4f; bgt 1f; lis 0,15988; ori 0,0,28918; cmpw 3,0; beq 3f; lis 0,20802; ori 0,0,20157; cmpw 3,0; beq 5f; b 6f; 1:; lis 0,25409; ori 0,0,27553; cmpw 3,0; beq 2f; lis 0,32656; ori 0,0,28789; cmpw 3,0; bne 6f; cmpwi 31,1; ble 6f; li 29,1; li 31,1; b 6f; 2:; cmpwi 31,6; ble 6f; li 29,2; li 31,6; b 6f; 3:; cmpwi 31,2; ble 6f; li 29,4; li 31,2; b 6f; 4:; cmpwi 31,4; ble 6f; li 29,5; li 31,4; b 6f; 5:; cmpwi 31,5; ble 6f; li 29,8; li 31,5; 6:; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s80068680_2; cmpwi 3,0; beq 12f; lwz 9,0x4(30); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,30,3; blrl; bl _s80068680_3; bl _s80068680_4; lis 0,12318; ori 0,0,40625; cmpw 3,0; beq 11f; bgt 8f; lis 0,-1552; ori 0,0,100; cmpw 3,0; beq 11f; bgt 7f; lis 0,-10846; ori 0,0,46379; b 9f; 7:; lis 0,1314; ori 0,0,50908; cmpw 3,0; beq 11f; lis 0,9778; ori 0,0,37547; b 9f; 8:; lis 0,22160; ori 0,0,62341; cmpw 3,0; beq 11f; bgt 10f; lis 0,20810; ori 0,0,4188; cmpw 3,0; beq 11f; lis 0,21663; ori 0,0,47788; 9:; cmpw 3,0; beq 11f; b 12f; 10:; lis 0,22858; ori 0,0,12509; cmpw 3,0; beq 11f; lis 0,31226; ori 0,0,32363; cmpw 3,0; bne 12f; 11:; cmpwi 31,3; ble 12f; li 29,7; li 31,3; 12:; addi 3,1,8; bl _s80068680_5; lwz 0,0x4(28); cmpwi 0,0; bne 0b; 13:; cmpwi 29,-1; bne 28f; lwz 11,-21488(13); mr 4,27; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32697; li 0,0; lwz 11,0x5ea0(9); lwz 11,0x0(11); cmpwi 11,0; beq 14f; lwz 0,-4(11); 14:; cmpw 3,0; bge 28f; rlwinm 9,3,2,0,29; lwzx 11,11,9; lwz 3,0x8(11); cmpwi 3,6; beq 20f; bgt 16f; cmpwi 3,2; beq 25f; bgt 15f; cmpwi 3,0; beq 23f; cmpwi 3,1; beq 24f; b 28f; 15:; cmpwi 3,4; beq 18f; bgt 19f; b 18f; 16:; cmpwi 3,10; beq 24f; bgt 17f; cmpwi 3,8; beq 22f; bgt 23f; b 21f; 17:; cmpwi 3,12; beq 26f; blt 25f; cmpwi 3,13; beq 27f; b 28f; 18:; li 29,0; b 28f; 19:; li 29,1; b 28f; 20:; li 29,2; b 28f; 21:; li 29,3; b 28f; 22:; li 29,4; b 28f; 23:; li 29,5; b 28f; 24:; li 29,6; b 28f; 25:; li 29,7; b 28f; 26:; li 29,8; b 28f; 27:; li 29,9; 28:; mr 3,29; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s80068680_0();
extern "C" void _s80068680_1();
extern "C" void _s80068680_2();
extern "C" void _s80068680_3();
extern "C" void _s80068680_4();
extern "C" void _s80068680_5();

struct SAnimator2 {
    void GetFootSound_CTilePt();
};

void SAnimator2::GetFootSound_CTilePt() {
}
