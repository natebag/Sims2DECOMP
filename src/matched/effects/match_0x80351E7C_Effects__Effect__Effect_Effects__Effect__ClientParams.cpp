// 0x80351E7C Effects::Effect::Effect(Effects::Effect::ClientParams (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; li 0,0; addi 9,9,-10728; li 11,0; mr 30,4; stw 9,0x144(31); sth 11,0x40(31); stw 0,0x4c(31); stw 0,0x44(31); stw 0,0x48(31); bl _s80351E7C_0; cmpw 31,30; beq 0f; lhz 0,0x40(30); sth 0,0x40(31); lwz 9,0x44(30); stw 9,0x44(31); lwz 0,0x48(30); stw 0,0x48(31); lwz 11,0x4c(30); stw 11,0x4c(31); lwz 9,0x0(30); lwz 10,0x4(30); stw 9,0x0(31); stw 10,0x4(31); lwz 11,0x8(30); lwz 12,0xc(30); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x10(30); lwz 10,0x14(30); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x18(30); lwz 12,0x1c(30); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x20(30); lwz 10,0x24(30); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0x28(30); lwz 12,0x2c(30); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0x30(30); lwz 10,0x34(30); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0x38(30); lwz 12,0x3c(30); stw 11,0x38(31); stw 12,0x3c(31); 0:; mr 3,31; bl _s80351E7C_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80351E7C_0();
extern "C" void _s80351E7C_1();

struct Effects {
    void Effect__Effect_Effects__Effect__ClientParams();
};

void Effects::Effect__Effect_Effects__Effect__ClientParams() {
}
