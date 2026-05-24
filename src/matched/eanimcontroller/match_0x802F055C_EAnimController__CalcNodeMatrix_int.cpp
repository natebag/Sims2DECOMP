// 0x802F055C EAnimController::CalcNodeMatrix(int, (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,5; mr. 8,4; blt 1f; lwz 9,0x24(30); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpw 8,0; blt 2f; 1:; mr 3,31; bl _s802F055C_0; b 5f; 2:; lwz 4,0x10(30); cmpwi 4,0; beq 3f; rlwinm 8,8,6,0,25; add 8,8,4; lwz 9,0x0(8); lwz 10,0x4(8); stw 9,0x0(31); stw 10,0x4(31); lwz 11,0x8(8); lwz 12,0xc(8); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x18(8); lwz 12,0x1c(8); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x20(8); lwz 10,0x24(8); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0x28(8); lwz 12,0x2c(8); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0x30(8); lwz 10,0x34(8); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0x38(8); lwz 12,0x3c(8); stw 11,0x38(31); stw 12,0x3c(31); b 4f; 3:; mr 3,31; bl _s802F055C_1; 4:; lis 9,-32702; lfs f0,0x58(30); lfs f1,-4288(9); fcmpu 0,f0,f1; beq 5f; fdivs f1,f1,f0; mr 3,31; bl _s802F055C_2; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802F055C_0();
extern "C" void _s802F055C_1();
extern "C" void _s802F055C_2();

struct EAnimController {
    void CalcNodeMatrix();
};

void EAnimController::CalcNodeMatrix() {
}
