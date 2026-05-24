// 0x801B6C44 G2DTarget::ChangeContinueType(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; cmplwi 31,3; ble 0f; lis 3,-32705; addi 3,3,3960; crxor 6,6,6; bl _s801B6C44_0; 0:; lwz 0,0xa4(30); cmpwi 0,0; bne 1f; cmpwi 31,0; bne 1f; mr 3,30; bl _s801B6C44_1; 1:; lis 3,-32705; lwz 4,0xa4(30); stw 31,0xac(30); addi 3,3,4020; mr 5,31; crxor 6,6,6; bl _s801B6C44_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801B6C44_0();
extern "C" void _s801B6C44_1();
extern "C" void _s801B6C44_2();

struct G2DTarget {
    void ChangeContinueType();
};

void G2DTarget::ChangeContinueType() {
}
