// 0x801B1500 FAMTarget::OnDownKeyPressed(char (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x88(31); bl _s801B1500_0; lwz 0,0x88(31); cmpwi 0,2; beq 5f; bgt 0f; cmpwi 0,0; beq 1f; cmpwi 0,1; beq 3f; b 11f; 0:; cmpwi 0,3; beq 7f; cmpwi 0,4; beq 9f; b 11f; 1:; lwz 9,0x14c(31); li 0,0; addi 9,9,1; cmpw 9,3; stw 9,0x14c(31); bge 2f; mr 0,9; 2:; stw 0,0x14c(31); b 11f; 3:; lwz 9,0x160(31); addi 9,9,1; cmpw 9,3; bge 4f; stw 9,0x160(31); b 11f; 4:; li 0,0; stw 0,0x160(31); b 11f; 5:; lwz 9,0x164(31); addi 9,9,1; cmpw 9,3; bge 6f; stw 9,0x164(31); b 11f; 6:; li 0,0; stw 0,0x164(31); b 11f; 7:; lwz 9,0x15c(31); addi 9,9,1; cmpw 9,3; bge 8f; stw 9,0x15c(31); b 11f; 8:; li 0,0; stw 0,0x15c(31); b 11f; 9:; lwz 9,0x150(31); addi 9,9,1; cmpw 3,9; ble 10f; mr 3,9; 10:; lwz 0,0x158(31); stw 3,0x150(31); rlwinm 9,0,1,31,31; add 0,0,9; srawi 0,0,1; cmpw 3,0; bne 11f; li 0,1; stw 0,0x168(31); 11:; mr 3,31; bl _s801B1500_1; mr 3,31; bl _s801B1500_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801B1500_0();
extern "C" void _s801B1500_1();
extern "C" void _s801B1500_2();

struct FAMTarget {
    void OnDownKeyPressed();
};

void FAMTarget::OnDownKeyPressed() {
}
