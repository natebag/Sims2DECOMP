// 0x802ED9AC EAnimController::SetTrackIntensity(eTrackFlags, (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32702; lfs f13,-4452(9); fcmpu 0,f1,f13; bge 0f; fmr f1,f13; 0:; lis 9,-32702; lfs f0,-4448(9); fcmpu 0,f1,f0; ble 1f; fmr f1,f0; 1:; fcmpu 0,f1,f13; cror 3,2,1; bso 2f; fmr f1,f13; 2:; lis 0,1; ori 0,0,255; and. 9,4,0; beq 5f; lwz 0,0x8(3); mr 11,0; cmpwi 0,-1; beq 3f; mulli 9,11,176; lwz 0,0x44(3); add 9,9,0; lwz 0,0x30(9); b 4f; 3:; li 0,0; 4:; and. 9,0,4; beq 20f; mulli 9,11,176; b 19f; 5:; cmpwi 4,2048; beq 12f; bgt 7f; cmpwi 4,512; beq 10f; bgt 6f; cmpwi 4,256; beq 9f; b 17f; 6:; cmpwi 4,1024; beq 11f; b 17f; 7:; cmpwi 4,8192; beq 14f; bgt 8f; cmpwi 4,4096; beq 13f; b 17f; 8:; cmpwi 4,16384; beq 15f; li 0,0; ori 0,0,32768; cmpw 4,0; beq 16f; b 17f; 9:; lwz 9,0x38(3); b 18f; 10:; lwz 9,0x38(3); addi 9,9,1; b 18f; 11:; lwz 9,0x38(3); addi 9,9,2; b 18f; 12:; lwz 9,0x38(3); addi 9,9,3; b 18f; 13:; lwz 9,0x38(3); addi 9,9,4; b 18f; 14:; lwz 9,0x38(3); addi 9,9,5; b 18f; 15:; lwz 9,0x38(3); addi 9,9,6; b 18f; 16:; lwz 9,0x38(3); addi 9,9,7; b 18f; 17:; li 9,-1; 18:; cmpwi 9,-1; beq 20f; mulli 9,9,176; 19:; lwz 0,0x44(3); add 4,0,9; b 21f; 20:; li 4,0; 21:; cmpwi 4,0; beq 22f; lwz 0,0xa8(4); cmpwi 0,1; bne 22f; li 5,1; bl _s802ED9AC_0; 22:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802ED9AC_0();

struct EAnimController {
    void SetTrackIntensity();
};

void EAnimController::SetTrackIntensity() {
}
