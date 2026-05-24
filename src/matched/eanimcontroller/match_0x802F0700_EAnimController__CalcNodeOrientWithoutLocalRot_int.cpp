// 0x802F0700 EAnimController::CalcNodeOrientWithoutLocalRot(int, (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-232(1); mfspr 0,8; stmw 25,0xcc(1); stw 0,0xec(1); mr 30,3; mr 31,5; mr. 29,4; blt 1f; lwz 9,0x24(30); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpw 29,0; blt 2f; 1:; mr 3,31; bl _s802F0700_0; b 6f; 2:; mr 3,30; mr 4,29; addi 5,1,8; bl _s802F0700_1; lwz 3,0x24(30); cmpwi 3,0; beq 4f; lwz 3,0x14(3); cmpwi 3,0; beq 4f; mulli 0,29,184; add 29,3,0; lwz 9,0xb0(29); cmpwi 9,0; beq 3f; addi 4,29,16; addi 3,1,72; bl _s802F0700_2; b 5f; 3:; addi 30,1,72; mr 3,30; bl _s802F0700_3; mr 3,30; addi 4,29,16; bl _s802F0700_4; b 5f; 4:; addi 3,1,72; bl _s802F0700_5; 5:; addi 3,1,136; addi 4,1,72; addi 5,1,8; bl _s802F0700_6; lwz 11,0x88(1); lwz 12,0x8c(1); lwz 7,0x90(1); lwz 8,0x94(1); lwz 5,0x98(1); lwz 6,0x9c(1); lwz 3,0xa0(1); lwz 4,0xa4(1); lwz 29,0xa8(1); lwz 30,0xac(1); lwz 27,0xb0(1); lwz 28,0xb4(1); lwz 25,0xb8(1); lwz 26,0xbc(1); lwz 9,0xc0(1); lwz 10,0xc4(1); stw 11,0x0(31); stw 12,0x4(31); stw 9,0x38(31); stw 10,0x3c(31); stw 7,0x8(31); stw 8,0xc(31); stw 5,0x10(31); stw 6,0x14(31); stw 3,0x18(31); stw 4,0x1c(31); stw 29,0x20(31); stw 30,0x24(31); stw 27,0x28(31); stw 28,0x2c(31); stw 25,0x30(31); stw 26,0x34(31); 6:; lwz 0,0xec(1); mtspr 8,0; lmw 25,0xcc(1); addi 1,1,232"

extern "C" void _s802F0700_0();
extern "C" void _s802F0700_1();
extern "C" void _s802F0700_2();
extern "C" void _s802F0700_3();
extern "C" void _s802F0700_4();
extern "C" void _s802F0700_5();
extern "C" void _s802F0700_6();

struct EAnimController {
    void CalcNodeOrientWithoutLocalRot();
};

void EAnimController::CalcNodeOrientWithoutLocalRot() {
}
