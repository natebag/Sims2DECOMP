// 0x80063234 SAnimator2::SetNextStateFromCompletedTurn(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0xb0(31); cmpwi 0,12; beq 0f; cmpwi 0,9; bne 1f; 0:; mr 3,31; bl _s80063234_0; li 0,9; b 4f; 1:; cmpwi 0,14; bne 3f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x178(9); lwz 9,0x17c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 2f; mr 3,31; bl _s80063234_1; cmpwi 3,0; beq 3f; 2:; mr 3,31; bl _s80063234_2; li 0,13; b 4f; 3:; lwz 0,0x2c(31); lwz 4,0xb0(31); cmpw 0,4; beq 5f; mr 3,31; bl _s80063234_3; lwz 0,0xb0(31); 4:; stw 0,0x2c(31); 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80063234_0();
extern "C" void _s80063234_1();
extern "C" void _s80063234_2();
extern "C" void _s80063234_3();

struct SAnimator2 {
    void SetNextStateFromCompletedTurn();
};

void SAnimator2::SetNextStateFromCompletedTurn() {
}
