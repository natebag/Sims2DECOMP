// 0x8012C16C cXPersonImpl::SetIdlePlayerSimAutonomous(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8012C16C_0; lis 9,-32697; lwz 11,0x4(30); addi 9,9,24012; mr 10,3; lwz 0,0xbc(9); li 3,0; cmpw 11,0; bne 0f; mr 3,10; li 4,0; li 5,0; bl _s8012C16C_1; b 1f; 0:; lwz 0,0xc0(9); cmpw 11,0; bne 1f; mr 3,10; li 4,1; li 5,0; bl _s8012C16C_2; 1:; cmpwi 3,0; beq 2f; bl _s8012C16C_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8012C16C_0();
extern "C" void _s8012C16C_1();
extern "C" void _s8012C16C_2();
extern "C" void _s8012C16C_3();

struct cXPersonImpl {
    void SetIdlePlayerSimAutonomous();
};

void cXPersonImpl::SetIdlePlayerSimAutonomous() {
}
