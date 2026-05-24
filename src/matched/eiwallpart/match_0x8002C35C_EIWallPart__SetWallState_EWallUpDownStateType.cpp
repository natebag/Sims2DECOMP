// 0x8002C35C EIWallPart::SetWallState(EWallUpDownStateType, (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; cmpwi 5,0; bne 1f; bl _s8002C35C_0; addi 9,31,812; rlwinm 3,3,2,0,29; lwzx 0,9,3; mr 29,9; cmpwi 0,27; bne 0f; cmpwi 30,0; bne 0f; bl _s8002C35C_1; rlwinm 3,3,2,0,29; addi 9,31,932; lis 11,-32707; lfsx f13,9,3; lfs f0,0xdd0(11); fcmpu 0,f13,f0; beq 5f; 0:; bl _s8002C35C_2; rlwinm 3,3,2,0,29; lwzx 0,29,3; cmpwi 0,21; bne 1f; cmpwi 30,2; bne 1f; bl _s8002C35C_3; rlwinm 3,3,2,0,29; addi 9,31,932; lis 11,-32707; lfsx f13,9,3; lfs f0,0xdd4(11); fcmpu 0,f13,f0; beq 5f; 1:; cmpwi 30,0; bne 2f; bl _s8002C35C_4; lis 11,-32707; addi 9,31,932; lfs f0,0xdd0(11); rlwinm 3,3,2,0,29; stfsx f0,9,3; bl _s8002C35C_5; rlwinm 3,3,2,0,29; addi 9,31,812; li 0,27; b 4f; 2:; cmpwi 30,1; bne 3f; bl _s8002C35C_6; rlwinm 3,3,2,0,29; addi 9,31,812; li 0,31; b 4f; 3:; bl _s8002C35C_7; lis 11,-32707; addi 9,31,932; lfs f0,0xdd4(11); rlwinm 3,3,2,0,29; stfsx f0,9,3; bl _s8002C35C_8; rlwinm 3,3,2,0,29; addi 9,31,812; li 0,21; 4:; stwx 0,9,3; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8002C35C_0();
extern "C" void _s8002C35C_1();
extern "C" void _s8002C35C_2();
extern "C" void _s8002C35C_3();
extern "C" void _s8002C35C_4();
extern "C" void _s8002C35C_5();
extern "C" void _s8002C35C_6();
extern "C" void _s8002C35C_7();
extern "C" void _s8002C35C_8();

struct EIWallPart {
    void SetWallState_EWallUpDownStateType();
};

void EIWallPart::SetWallState_EWallUpDownStateType() {
}
