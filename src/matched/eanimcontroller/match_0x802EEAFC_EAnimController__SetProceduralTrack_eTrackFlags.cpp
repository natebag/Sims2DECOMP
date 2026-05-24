// 0x802EEAFC EAnimController::SetProceduralTrack(eTrackFlags, (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 0,1; mr 28,4; ori 0,0,255; mr 29,3; mr 27,5; mr 26,6; mr 25,7; and. 9,28,0; beq 2f; lwz 0,0x8(29); mr 11,0; cmpwi 0,-1; beq 0f; mulli 9,11,176; lwz 0,0x44(29); add 9,9,0; lwz 0,0x30(9); b 1f; 0:; li 0,0; 1:; and. 9,0,28; beq 17f; mulli 9,11,176; b 16f; 2:; cmpwi 28,2048; beq 9f; bgt 4f; cmpwi 28,512; beq 7f; bgt 3f; cmpwi 28,256; beq 6f; b 14f; 3:; cmpwi 28,1024; beq 8f; b 14f; 4:; cmpwi 28,8192; beq 11f; bgt 5f; cmpwi 28,4096; beq 10f; b 14f; 5:; cmpwi 28,16384; beq 12f; li 0,0; ori 0,0,32768; cmpw 28,0; beq 13f; b 14f; 6:; lwz 9,0x38(29); b 15f; 7:; lwz 9,0x38(29); addi 9,9,1; b 15f; 8:; lwz 9,0x38(29); addi 9,9,2; b 15f; 9:; lwz 9,0x38(29); addi 9,9,3; b 15f; 10:; lwz 9,0x38(29); addi 9,9,4; b 15f; 11:; lwz 9,0x38(29); addi 9,9,5; b 15f; 12:; lwz 9,0x38(29); addi 9,9,6; b 15f; 13:; lwz 9,0x38(29); addi 9,9,7; b 15f; 14:; li 9,-1; 15:; cmpwi 9,-1; beq 17f; mulli 9,9,176; 16:; lwz 0,0x44(29); add 31,0,9; b 18f; 17:; li 31,0; 18:; cmpwi 31,0; beq 21f; lwz 0,0x24(31); cmpw 0,27; bne 19f; lwz 0,0x28(31); cmpw 0,26; bne 19f; stw 25,0x2c(31); b 21f; 19:; mr 3,29; mr 4,31; bl _s802EEAFC_0; li 30,0; lwz 3,0x7c(31); cmpwi 3,0; beq 20f; bl _s802EEAFC_1; stw 30,0x7c(31); 20:; lis 9,-32702; lis 11,-32702; lfs f0,-4384(9); li 0,-1; lfs f13,-4380(11); mr 3,29; stw 27,0x24(31); mr 4,31; stw 26,0x28(31); li 5,1; stw 25,0x2c(31); stw 28,0x30(31); stw 30,0xa8(31); stw 30,0x7c(31); stb 30,0xa0(31); stw 30,0x98(31); stw 30,0x9c(31); stw 30,0xac(31); stw 0,0x74(31); stfs f0,0x78(31); stfs f13,0x50(31); stfs f0,0x3c(31); stfs f0,0x40(31); stfs f13,0x4c(31); stfs f13,0x0(31); stfs f0,0x5c(31); bl _s802EEAFC_2; 21:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s802EEAFC_0();
extern "C" void _s802EEAFC_1();
extern "C" void _s802EEAFC_2();

struct EAnimController {
    void SetProceduralTrack();
};

void EAnimController::SetProceduralTrack() {
}
