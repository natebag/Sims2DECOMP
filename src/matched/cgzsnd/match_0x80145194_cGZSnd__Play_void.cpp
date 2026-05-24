// 0x80145194 cGZSnd::Play(void) (712 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x1c(1); mr 30,3; bl _s80145194_0; lis 9,-32698; li 0,0; addi 9,9,19024; stw 0,0x54(30); stw 9,0x0(30); addi 11,30,92; stw 0,0x58(30); mr 3,30; stw 0,0x4(11); stw 0,0x64(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,19024; addi 11,31,84; stw 9,0x0(31); mr 30,4; lwz 9,0x54(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,72; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,14563; ori 9,9,36409; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,72; cmplwi 4,128; ble 2f; bl _s80145194_1; b 3f; 2:; bl _s80145194_2; 3:; mr 3,31; mr 4,30; bl _s80145194_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; lwz 9,0x54(3); lis 0,14563; lwz 3,0x58(3); ori 0,0,36409; subf 3,9,3; mullw 3,3,0; srawi 3,3,3; blr; mulli 4,4,72; lwz 3,0x54(3); add 3,3,4; blr; li 3,0; blr; blr; li 3,2; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,18992; stw 9,0x0(3); beq 4f; bl _s80145194_4; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,18992; stw 9,0x0(3); beq 5f; bl _s80145194_5; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x8(3); blr; lwz 0,0x10(3); li 3,0; andi. 9,0,1; beqlr; li 3,1; blr; lwz 3,0x10(3); rlwinm 3,3,31,31,31; blr; addi 0,3,-1; li 3,1; slw 3,3,0; blr; li 3,12; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,-1; bl _s80145194_6; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; bl _s80145194_7; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 0,0x10(3); li 3,1; cmpwi 0,0; bnelr; li 3,0; blr; stw 4,0x3c(3); blr; stw 4,0x40(3); blr; stw 4,0x48(3); blr; stfs f1,0x5c(3); blr; lwz 0,0x18(3); cmpwi 0,-1; beq 6f; li 3,0; blr; 6:; lwz 3,0x28(3); blr; lwz 3,0x18(3); blr; lwz 3,0x3c(3); blr; lwz 3,0x40(3); blr; lwz 3,0x30(3); blr; lwz 3,0x64(3); blr; stw 4,0x44(3); blr; lwz 3,0x44(3); blr; lwz 3,0x48(3); blr; lwz 3,0x48(3); rlwinm 3,3,28,31,31; blr; lwz 3,0x60(3)"

extern "C" void _s80145194_0();
extern "C" void _s80145194_1();
extern "C" void _s80145194_2();
extern "C" void _s80145194_3();
extern "C" void _s80145194_4();
extern "C" void _s80145194_5();
extern "C" void _s80145194_6();
extern "C" void _s80145194_7();

struct cGZSnd {
    void Play();
};

void cGZSnd::Play() {
}
