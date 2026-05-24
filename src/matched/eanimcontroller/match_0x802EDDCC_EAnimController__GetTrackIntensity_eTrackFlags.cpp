// 0x802EDDCC EAnimController::GetTrackIntensity(eTrackFlags) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,1; ori 0,0,255; and. 9,4,0; beq 2f; lwz 0,0x8(3); mr 11,0; cmpwi 0,-1; beq 0f; mulli 9,11,176; lwz 0,0x44(3); add 9,9,0; lwz 0,0x30(9); b 1f; 0:; li 0,0; 1:; and. 9,0,4; beq 17f; mulli 9,11,176; b 16f; 2:; cmpwi 4,2048; beq 9f; bgt 4f; cmpwi 4,512; beq 7f; bgt 3f; cmpwi 4,256; beq 6f; b 14f; 3:; cmpwi 4,1024; beq 8f; b 14f; 4:; cmpwi 4,8192; beq 11f; bgt 5f; cmpwi 4,4096; beq 10f; b 14f; 5:; cmpwi 4,16384; beq 12f; li 0,0; ori 0,0,32768; cmpw 4,0; beq 13f; b 14f; 6:; lwz 9,0x38(3); b 15f; 7:; lwz 9,0x38(3); addi 9,9,1; b 15f; 8:; lwz 9,0x38(3); addi 9,9,2; b 15f; 9:; lwz 9,0x38(3); addi 9,9,3; b 15f; 10:; lwz 9,0x38(3); addi 9,9,4; b 15f; 11:; lwz 9,0x38(3); addi 9,9,5; b 15f; 12:; lwz 9,0x38(3); addi 9,9,6; b 15f; 13:; lwz 9,0x38(3); addi 9,9,7; b 15f; 14:; li 9,-1; 15:; cmpwi 9,-1; beq 17f; mulli 9,9,176; 16:; lwz 0,0x44(3); add 3,0,9; b 18f; 17:; li 3,0; 18:; cmpwi 3,0; beq 19f; lwz 0,0xa8(3); cmpwi 0,1; bne 19f; lfs f1,0x50(3); blr; 19:; lis 9,-32702; lfs f1,-4428(9)"

struct EAnimController {
    void GetTrackIntensity();
};

void EAnimController::GetTrackIntensity() {
}
