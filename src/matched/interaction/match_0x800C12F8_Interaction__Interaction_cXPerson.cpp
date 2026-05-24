// 0x800C12F8 Interaction::Interaction(cXPerson (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; mr 31,3; addi 9,9,-2280; mr 30,5; mr 29,4; stw 9,0x40(31); addi 3,31,52; li 26,-1; bl _s800C12F8_0; lwz 9,0x4(30); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,30,3; blrl; mr 30,3; mr 3,31; mr 4,30; bl _s800C12F8_1; lwz 0,0x3c(31); li 9,1; lwz 10,0xc(31); li 11,50; rlwinm 0,0,0,31,28; stw 9,0x4(31); cmpwi 10,0; stw 29,0x8(31); stw 11,0x28(31); stw 0,0x3c(31); beq 0f; lwz 9,0x4(10); lha 3,0x360(9); lwz 0,0x364(9); add 3,10,3; mtspr 8,0; blrl; mr. 28,3; beq 0f; lwz 9,0x0(28); lwz 4,0x14(30); lha 3,0x88(9); lwz 0,0x8c(9); add 3,28,3; mtspr 8,0; blrl; mr. 27,3; beq 0f; lwz 9,0x0(27); lwz 11,0x0(28); lwz 0,0xbc(9); lha 3,0xb8(9); addi 29,11,136; mtspr 8,0; lha 30,0x88(11); add 3,27,3; add 30,28,30; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x0(27); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,27,3; mtspr 8,0; blrl; mr 26,3; 0:; cmpwi 26,-1; bne 1f; li 0,0; stw 0,0xc(31); b 2f; 1:; stw 26,0x14(31); 2:; li 0,0; li 9,0; sth 0,0x1e(31); mr 3,31; stw 9,0x38(31); sth 0,0x18(31); sth 0,0x1a(31); sth 0,0x1c(31); bl _s800C12F8_2; mr. 27,3; beq 3f; lwz 9,0x0(27); addi 28,31,52; lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,27,3; blrl; sth 3,0x2c(31); lwz 11,0x8(31); lwz 30,0x0(27); lwz 9,0x4(11); lha 29,0x158(30); lwz 0,0x1d4(9); addi 30,30,344; lha 3,0x1d0(9); add 29,27,29; mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; stfs f1,0x30(31); lwz 9,0x0(27); lwz 0,0x1a4(9); lha 3,0x1a0(9); mtspr 8,0; add 3,27,3; blrl; mr 4,3; mr 3,28; bl _s800C12F8_3; lwz 9,0x0(27); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,27,3; blrl; lwz 0,0x3c(31); cmpwi 3,0; rlwinm 0,0,0,0,30; stw 0,0x3c(31); beq 5f; ori 0,0,1; b 4f; 3:; lis 9,-32706; sth 27,0x2c(31); lfs f0,-24756(9); lis 4,-32706; addi 4,4,-24764; addi 3,31,52; stfs f0,0x30(31); bl _s800C12F8_4; lwz 0,0x3c(31); rlwinm 0,0,0,0,30; 4:; stw 0,0x3c(31); 5:; li 0,0; mr 3,31; stw 0,0x24(31); stw 0,0x20(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800C12F8_0();
extern "C" void _s800C12F8_1();
extern "C" void _s800C12F8_2();
extern "C" void _s800C12F8_3();
extern "C" void _s800C12F8_4();

struct Interaction {
    void Interaction_cXPerson();
};

void Interaction::Interaction_cXPerson() {
}
