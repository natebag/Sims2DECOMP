// 0x80152DDC XRoute::Construct(cXObject (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 0,0; stw 4,0x50(31); mr. 6,6; stw 5,0x4c(31); stw 0,0x84(31); stw 0,0x80(31); beq 1f; lwz 0,0x10(31); addi 11,31,16; li 10,48; stw 0,0x8(1); 0:; lwz 9,0x0(6); addic. 10,10,-24; stw 9,0x0(11); lwz 9,0x4(6); stw 9,0x4(11); lwz 9,0x8(6); stw 9,0x8(11); lwz 9,0xc(6); stw 9,0xc(11); lwz 9,0x10(6); stw 9,0x10(11); lwz 9,0x14(6); addi 6,6,24; stw 9,0x14(11); addi 11,11,24; bne 0b; lwz 9,0x0(6); lwz 0,0x8(1); stw 9,0x0(11); lwz 9,0x4(6); stw 9,0x4(11); lwz 9,0x8(6); stw 9,0x8(11); stw 0,0x10(31); 1:; lwz 11,0x50(31); li 0,-1; li 30,0; stw 0,0x58(31); stw 0,0x54(31); cmpwi 11,0; stw 30,0x5c(31); stw 30,0x60(31); beq 2f; lwz 9,0x4(11); addi 4,31,100; lha 3,0x338(9); lwz 0,0x33c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 3,0x50(31); li 0,1; stw 0,0x7c(31); sth 30,0x9c(31); cmpwi 3,0; stw 30,0x6c(31); stw 30,0x88(31); stw 30,0x8c(31); sth 30,0x90(31); stw 30,0x94(31); beq 3f; lwz 3,0x0(3); li 4,2; bl _s80152DDC_0; mr 30,3; b 4f; 3:; li 30,0; 4:; cmpwi 30,0; beq 5f; lwz 9,0x4(30); li 4,72; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; sth 3,0x9c(31); lwz 9,0x4(30); lha 3,0x328(9); lwz 0,0x32c(9); add 3,30,3; mtspr 8,0; blrl; 5:; li 0,48; stw 0,0xa0(31); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80152DDC_0();

struct XRoute {
    void Construct_cXObject();
};

void XRoute::Construct_cXObject() {
}
