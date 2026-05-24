// 0x800C1574 Interaction::Interaction(cXPerson (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32698; mr 31,3; addi 9,9,-2280; mr 29,4; mr 28,5; mr 30,7; mr 27,6; stw 9,0x40(31); addi 3,31,52; bl _s800C1574_0; li 0,0; stw 30,0x28(31); stw 0,0x3c(31); cmpwi 28,0; stw 29,0x8(31); stw 0,0x4(31); bne 0f; li 0,-1; stw 28,0x10(31); stw 0,0x14(31); b 1f; 0:; stw 28,0x10(31); stw 27,0x14(31); 1:; stw 28,0xc(31); li 0,0; li 9,0; sth 0,0x1e(31); mr 3,31; stw 9,0x38(31); sth 0,0x18(31); sth 0,0x1a(31); sth 0,0x1c(31); bl _s800C1574_1; mr. 28,3; beq 3f; lwz 9,0x0(28); lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,28,3; blrl; sth 3,0x2c(31); lwz 11,0x8(31); lwz 30,0x0(28); lwz 9,0x4(11); lha 29,0x158(30); lwz 0,0x1d4(9); addi 30,30,344; lha 3,0x1d0(9); add 29,28,29; mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; stfs f1,0x30(31); lwz 9,0x0(28); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0x3c(31); cmpwi 3,0; rlwinm 0,0,0,0,30; stw 0,0x3c(31); beq 2f; ori 0,0,1; stw 0,0x3c(31); 2:; lwz 9,0x0(28); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0x3c(31); cmpwi 3,0; rlwinm 0,0,0,22,20; stw 0,0x3c(31); beq 5f; ori 0,0,1024; b 4f; 3:; lwz 0,0x3c(31); lis 9,-32706; lfs f0,-24752(9); rlwinm 0,0,0,0,30; sth 28,0x2c(31); rlwinm 0,0,0,22,20; stfs f0,0x30(31); 4:; stw 0,0x3c(31); 5:; li 0,0; mr 3,31; stw 0,0x24(31); stw 0,0x20(31); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800C1574_0();
extern "C" void _s800C1574_1();

struct Interaction {
    void Interaction_cXPerson();
};

void Interaction::Interaction_cXPerson() {
}
