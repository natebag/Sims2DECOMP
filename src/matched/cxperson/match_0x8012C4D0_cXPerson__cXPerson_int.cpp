// 0x8012C4D0 cXPerson::cXPerson(int) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-368(1); mfspr 0,8; stmw 30,0x168(1); stw 0,0x174(1); mr 31,3; mr. 30,4; beq 1f; addi 9,31,8; addi 0,31,36; mr 3,9; stw 9,0x24(31); stw 0,0x0(31); bl _s8012C4D0_0; lwz 5,0x0(31); lis 9,-32698; addi 9,9,5344; addi 7,1,8; lwz 11,0x0(5); mr 4,7; mr 6,9; li 10,168; stw 9,0x18(11); 0:; lwz 0,0x0(6); addic. 10,10,-24; stw 0,0x0(7); lwz 0,0x4(6); stw 0,0x4(7); lwz 0,0x8(6); stw 0,0x8(7); lwz 0,0xc(6); stw 0,0xc(7); lwz 0,0x10(6); stw 0,0x10(7); lwz 0,0x14(6); addi 6,6,24; stw 0,0x14(7); addi 7,7,24; bne 0b; lwz 0,0x0(6); lis 8,-32698; lis 10,-32698; stw 0,0x0(7); addi 10,10,4016; lwz 0,0x4(6); stw 0,0x4(7); lwz 11,0x0(5); stw 4,0x18(11); lwz 9,0x0(5); lhz 0,0x14e8(8); addi 9,9,-8; subf 9,9,5; add 0,0,9; sth 0,0x10(1); stw 10,0x4(5); 1:; lwz 8,0x0(31); lis 9,-32698; addi 0,9,12696; lis 11,-32698; lwz 10,0x0(8); addi 11,11,4016; cmpwi 30,0; stw 0,0x18(10); lwz 9,0x0(31); stw 11,0x4(9); bne 3f; addi 8,1,184; mr 7,0; mr 6,8; li 0,168; 2:; lwz 10,0x0(7); addic. 0,0,-24; stw 10,0x0(8); lwz 10,0x4(7); stw 10,0x4(8); lwz 10,0x8(7); stw 10,0x8(8); lwz 10,0xc(7); stw 10,0xc(8); lwz 10,0x10(7); stw 10,0x10(8); lwz 10,0x14(7); addi 7,7,24; stw 10,0x14(8); addi 8,8,24; bne 2b; lwz 10,0x0(7); lis 9,-32698; lwz 11,0x0(31); stw 10,0x0(8); lwz 10,0x4(7); lhz 0,0x31a0(9); stw 10,0x4(8); lwz 9,0x0(11); stw 6,0x18(9); lwz 11,0x0(31); lwz 9,0x0(11); addi 9,9,-8; subf 9,9,31; add 0,0,9; sth 0,0xc0(1); 3:; lis 9,-32698; mr 3,31; addi 9,9,11720; stw 9,0x4(31); lwz 0,0x174(1); mtspr 8,0; lmw 30,0x168(1); addi 1,1,368"

extern "C" void _s8012C4D0_0();

struct cXPerson {
    void cXPerson();
};

void cXPerson::cXPerson() {
}
