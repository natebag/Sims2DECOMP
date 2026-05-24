// 0x800407DC EGlobal::SetSelectedPerson(int, (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 27,4; mr. 28,5; bne 1f; rlwinm 0,27,2,0,29; addi 9,31,188; stwx 28,9,0; cmpwi 27,0; lwz 11,-21496(13); li 4,3; lwz 9,0x0(11); lha 0,0x38(9); addi 10,9,56; add 3,11,0; beq 0f; li 4,32; 0:; lwz 0,0x4(10); li 5,0; mtspr 8,0; blrl; 1:; addi 9,31,188; rlwinm 0,27,2,0,29; lwzx 31,9,0; mr 25,0; mr 26,9; cmpw 31,28; beq 8f; cmpwi 31,0; beq 2f; lwz 30,0x0(31); lwz 9,0x4(30); lwz 11,0x6c(9); addi 29,9,96; lha 3,0x68(9); mtspr 8,11; lha 0,0x60(9); add 3,30,3; add 30,30,0; blrl; lwz 0,0x4(29); rlwinm 4,3,0,31,29; mr 3,30; mtspr 8,0; blrl; lwz 9,0x4(31); lha 3,0x188(9); lwz 0,0x18c(9); add 3,31,3; mtspr 8,0; blrl; li 4,0; bl _s800407DC_0; 2:; cmpwi 28,0; beq 4f; stwx 28,26,25; lwz 30,0x0(28); lwz 9,0x4(30); lwz 11,0x6c(9); addi 29,9,96; lha 3,0x68(9); mtspr 8,11; lha 0,0x60(9); add 3,30,3; add 30,30,0; blrl; lwz 0,0x4(29); ori 4,3,2; mr 3,30; mtspr 8,0; blrl; lwz 9,0x4(28); lha 3,0x188(9); lwz 0,0x18c(9); add 3,28,3; mtspr 8,0; blrl; li 4,1; bl _s800407DC_1; lwz 10,0x0(28); li 5,0; lwz 9,0x0(10); lwz 11,0x14(9); addi 3,11,968; cmpwi 11,0; beq 3f; mr 5,3; 3:; mr 4,27; bl _s800407DC_2; 4:; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 5f; mr 5,28; mr 4,27; bl _s800407DC_3; 5:; lwzx 3,26,25; li 5,0; cmpwi 3,0; beq 6f; lwz 3,0x0(3); lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; mr 5,3; 6:; cmpwi 27,0; li 4,32; bne 7f; li 4,3; 7:; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800407DC_0();
extern "C" void _s800407DC_1();
extern "C" void _s800407DC_2();
extern "C" void _s800407DC_3();

struct EGlobal {
    void SetSelectedPerson();
};

void EGlobal::SetSelectedPerson() {
}
