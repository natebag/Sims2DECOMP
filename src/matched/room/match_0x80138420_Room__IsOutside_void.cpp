// 0x80138420 Room::IsOutside(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 0,0x34(30); cmpwi 0,0; bne 1f; li 3,0; b 7f; 0:; lwz 11,-21488(13); mr 4,31; lwz 9,0x0(11); lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,11,3; blrl; rlwinm 3,3,30,31,31; li 0,1; stw 3,0x8c(30); stw 0,0x88(30); b 3f; 1:; lwz 0,0x88(30); cmpwi 0,0; bne 6f; addi 9,30,4; lwz 31,0x4(30); lwz 0,0x4(9); mr 29,9; cmpw 31,0; beq 3f; 2:; lwz 11,-21488(13); mr 4,31; lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0x0(30); cmpw 3,0; beq 0b; lwz 0,0x4(29); addi 31,31,3; cmpw 31,0; bne 2b; 3:; lwz 10,0x88(30); cmpwi 10,0; bne 6f; lwz 0,0x4(29); lis 9,-21846; lwz 11,0x4(30); ori 9,9,43691; subf 0,11,0; mullw 0,0,9; cmpwi 0,1; bne 4f; stw 0,0x8c(30); b 5f; 4:; stw 10,0x8c(30); 5:; li 0,1; stw 0,0x88(30); 6:; lwz 3,0x8c(30); 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct Room {
    void IsOutside();
};

void Room::IsOutside() {
}
