// 0x803042D4 EController::IsInUse(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; li 4,-1; li 30,0; bl _s803042D4_0; mr 4,3; li 5,0; mr 3,31; li 6,-1; bl _s803042D4_1; cmpwi 3,0; bne 0f; li 4,-1; mr 3,31; bl _s803042D4_2; mr 4,3; li 5,0; mr 3,31; li 6,-1; bl _s803042D4_3; cmpwi 3,0; bne 0f; li 4,-1; mr 3,31; bl _s803042D4_4; mr 4,3; li 5,0; mr 3,31; li 6,-1; bl _s803042D4_5; cmpwi 3,0; beq 1f; 0:; li 30,1; 1:; cmpwi 30,0; li 30,0; bne 2f; mr 3,31; li 4,0; li 5,0; li 6,-1; bl _s803042D4_6; lis 9,-32702; lfs f31,-1660(9); fcmpu 0,f1,f31; bne 2f; mr 3,31; li 4,0; li 5,1; li 6,-1; bl _s803042D4_7; fcmpu 0,f1,f31; bne 2f; mr 3,31; li 4,1; li 5,0; li 6,-1; bl _s803042D4_8; fcmpu 0,f1,f31; bne 2f; mr 3,31; li 4,1; li 5,1; li 6,-1; bl _s803042D4_9; fcmpu 0,f1,f31; beq 3f; 2:; li 30,1; 3:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s803042D4_0();
extern "C" void _s803042D4_1();
extern "C" void _s803042D4_2();
extern "C" void _s803042D4_3();
extern "C" void _s803042D4_4();
extern "C" void _s803042D4_5();
extern "C" void _s803042D4_6();
extern "C" void _s803042D4_7();
extern "C" void _s803042D4_8();
extern "C" void _s803042D4_9();

struct EController {
    void IsInUse();
};

void EController::IsInUse() {
}
