// 0x802EA2CC EAnimController::PostMultNodeAndDescendents(int, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 28,3; mr 27,5; mr. 31,4; blt 2f; lwz 9,0x24(28); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpw 31,0; bge 2f; mr 4,31; mr 3,28; bl _s802EA2CC_0; mr 30,3; mr 5,27; addi 3,1,8; mr 4,30; bl _s802EA2CC_1; lwz 11,0x8(1); lwz 12,0xc(1); addi 8,1,8; mulli 7,31,184; stw 11,0x0(30); stw 12,0x4(30); lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x8(30); stw 10,0xc(30); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x10(30); stw 12,0x14(30); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x18(30); stw 10,0x1c(30); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x20(30); stw 12,0x24(30); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x28(30); stw 10,0x2c(30); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x30(30); stw 12,0x34(30); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x38(30); stw 10,0x3c(30); lwz 11,0x24(28); lwz 0,0x14(11); add 29,0,7; lwz 0,0x8(29); cmpwi 0,0; ble 2f; mr 30,0; li 31,0; 1:; lwz 9,0x4(29); mr 3,28; mr 5,27; lwzx 4,9,31; addi 31,31,4; bl _s802EA2CC_2; addic. 30,30,-1; bne 1b; 2:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s802EA2CC_0();
extern "C" void _s802EA2CC_1();
extern "C" void _s802EA2CC_2();

struct EAnimController {
    void PostMultNodeAndDescendents();
};

void EAnimController::PostMultNodeAndDescendents() {
}
