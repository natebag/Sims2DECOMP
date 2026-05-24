// 0x801B13DC FAMTarget::OnUpKeyPressed(char (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x88(31); bl _s801B13DC_0; lwz 0,0x88(31); cmpwi 0,2; beq 5f; bgt 0f; cmpwi 0,0; beq 1f; cmpwi 0,1; beq 3f; b 11f; 0:; cmpwi 0,3; beq 7f; cmpwi 0,4; beq 9f; b 11f; 1:; lwz 9,0x14c(31); addi 9,9,-1; stw 9,0x14c(31); mr. 9,9; bge 2f; addi 9,3,-1; 2:; stw 9,0x14c(31); b 11f; 3:; lwz 0,0x160(31); addic. 0,0,-1; bge 4f; addi 0,3,-1; 4:; stw 0,0x160(31); b 11f; 5:; lwz 0,0x164(31); addic. 0,0,-1; bge 6f; addi 0,3,-1; 6:; stw 0,0x164(31); b 11f; 7:; lwz 0,0x15c(31); addic. 0,0,-1; bge 8f; addi 0,3,-1; 8:; stw 0,0x15c(31); b 11f; 9:; lwz 0,0x150(31); addic. 11,0,-1; bge 10f; li 11,0; 10:; lwz 9,0x158(31); stw 11,0x150(31); rlwinm 0,9,1,31,31; add 9,9,0; srawi 9,9,1; addi 9,9,-1; cmpw 11,9; bne 11f; lwz 0,0x168(31); cmpwi 0,1; bne 11f; li 0,0; stw 0,0x168(31); 11:; mr 3,31; bl _s801B13DC_1; mr 3,31; bl _s801B13DC_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801B13DC_0();
extern "C" void _s801B13DC_1();
extern "C" void _s801B13DC_2();

struct FAMTarget {
    void OnUpKeyPressed();
};

void FAMTarget::OnUpKeyPressed() {
}
