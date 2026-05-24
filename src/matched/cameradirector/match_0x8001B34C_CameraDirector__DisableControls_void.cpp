// 0x8001B34C CameraDirector::DisableControls(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x244(31); cmpwi 0,0; bne 0f; lwz 9,0x170(31); cmpwi 9,0; beq 0f; lwz 4,0x4(9); lwz 3,-26524(13); bl _s8001B34C_0; cmpwi 3,0; beq 0f; lwz 9,0x170(31); lwz 30,-26524(13); lwz 4,0x4(9); mr 3,30; bl _s8001B34C_1; mr 4,3; mr 3,30; bl _s8001B34C_2; mr. 3,3; beq 0f; lis 5,-32707; lis 4,15; addi 5,5,-6916; li 6,100; bl _s8001B34C_3; stw 3,0x244(31); lwz 9,0x170(31); lwz 0,0x4(9); stw 0,0x248(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8001B34C_0();
extern "C" void _s8001B34C_1();
extern "C" void _s8001B34C_2();
extern "C" void _s8001B34C_3();

struct CameraDirector {
    void DisableControls();
};

void CameraDirector::DisableControls() {
}
