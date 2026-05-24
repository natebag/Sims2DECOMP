// 0x802E96A8 EAnimController::GetAnimTranslate(eTrackFlags, (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f30,0x60(1); stfd f31,0x68(1); stmw 27,0x4c(1); stw 0,0x74(1); lis 0,1; mr 29,3; ori 0,0,255; mr 28,5; mr 27,6; and. 9,4,0; beq 2f; lwz 0,0x8(29); mr 11,0; cmpwi 0,-1; beq 0f; mulli 9,11,176; lwz 0,0x44(29); add 9,9,0; lwz 0,0x30(9); b 1f; 0:; li 0,0; 1:; and. 9,0,4; beq 17f; mulli 9,11,176; b 16f; 2:; cmpwi 4,2048; beq 9f; bgt 4f; cmpwi 4,512; beq 7f; bgt 3f; cmpwi 4,256; beq 6f; b 14f; 3:; cmpwi 4,1024; beq 8f; b 14f; 4:; cmpwi 4,8192; beq 11f; bgt 5f; cmpwi 4,4096; beq 10f; b 14f; 5:; cmpwi 4,16384; beq 12f; li 0,0; ori 0,0,32768; cmpw 4,0; beq 13f; b 14f; 6:; lwz 9,0x38(29); b 15f; 7:; lwz 9,0x38(29); addi 9,9,1; b 15f; 8:; lwz 9,0x38(29); addi 9,9,2; b 15f; 9:; lwz 9,0x38(29); addi 9,9,3; b 15f; 10:; lwz 9,0x38(29); addi 9,9,4; b 15f; 11:; lwz 9,0x38(29); addi 9,9,5; b 15f; 12:; lwz 9,0x38(29); addi 9,9,6; b 15f; 13:; lwz 9,0x38(29); addi 9,9,7; b 15f; 14:; li 9,-1; 15:; cmpwi 9,-1; beq 17f; mulli 9,9,176; 16:; lwz 0,0x44(29); add 31,0,9; b 18f; 17:; li 31,0; 18:; cmpwi 31,0; beq 22f; lwz 0,0xa8(31); cmpwi 0,1; bne 22f; lwz 0,0x7c(31); li 9,1; cmpwi 0,0; bne 19f; li 9,0; 19:; cmpwi 9,0; beq 22f; lis 9,-32702; lfs f30,0x40(31); lfs f31,-4624(9); addi 3,1,8; addi 30,1,24; mr 4,29; stfs f31,0x40(31); mr 5,31; bl _s802E96A8_0; lwz 8,0x7c(31); lis 0,17200; lis 10,-32702; lwz 9,0x18(8); mr 5,31; lfd f13,-4616(10); mr 4,29; addi 9,9,-1; mr 3,30; xoris 9,9,32768; stw 9,0x44(1); stw 0,0x40(1); lfd f0,0x40(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x40(31); bl _s802E96A8_1; stfs f30,0x40(31); addi 9,1,40; li 0,3; stfs f31,0x8(9); stfs f31,0x4(9); mtspr 9,0; mr 7,9; stfs f31,0x28(1); li 5,1; mr 6,7; li 8,0; addi 10,1,8; li 11,0; 20:; lwz 9,0x8(31); slw 0,5,8; and. 4,9,0; beq 21f; lfs f0,0x0(10); lfsx f13,11,30; lfsx f12,11,27; fsubs f13,f13,f0; fmuls f13,f13,f12; stfsx f13,11,6; 21:; addi 10,10,4; addi 11,11,4; addi 8,8,1; bdnz 20b; lwz 0,0x8(7); lwz 9,0x28(1); lwz 11,0x4(7); stw 0,0x8(28); stw 9,0x0(28); stw 11,0x4(28); b 23f; 22:; lis 11,-32702; addi 9,1,8; lfs f0,-4624(11); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); lwz 0,0x8(9); lwz 11,0x8(1); lwz 10,0x4(9); stw 0,0x8(28); stw 11,0x0(28); stw 10,0x4(28); 23:; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x4c(1); lfd f30,0x60(1); lfd f31,0x68(1); addi 1,1,112"

extern "C" void _s802E96A8_0();
extern "C" void _s802E96A8_1();

struct EAnimController {
    void GetAnimTranslate();
};

void EAnimController::GetAnimTranslate() {
}
