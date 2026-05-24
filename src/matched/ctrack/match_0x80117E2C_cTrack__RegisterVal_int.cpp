// 0x80117E2C cTrack::RegisterVal(int) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,12; beq 7f; bgt 1f; cmpwi 4,9; beq 4f; bgt 0f; cmpwi 4,1; blt 13f; b 3f; 0:; cmpwi 4,10; beq 5f; cmpwi 4,11; beq 6f; b 13f; 1:; cmpwi 4,15; beq 10f; bgt 2f; cmpwi 4,13; beq 8f; cmpwi 4,14; beq 9f; b 13f; 2:; cmpwi 4,16; beq 11f; cmpwi 4,17; beq 12f; b 13f; 3:; addi 0,4,-1; addi 9,3,84; rlwinm 0,0,2,0,29; lwzx 3,9,0; blr; 4:; lwz 3,0x74(3); blr; 5:; lwz 3,0x78(3); blr; 6:; lwz 3,0x7c(3); blr; 7:; lwz 3,0x80(3); blr; 8:; lwz 3,0x84(3); blr; 9:; lwz 3,0x88(3); blr; 10:; lwz 3,0x8c(3); blr; 11:; lwz 3,0x90(3); blr; 12:; lwz 3,-31776(13); blr; 13:; li 3,1"

struct cTrack {
    void RegisterVal();
};

void cTrack::RegisterVal() {
}
