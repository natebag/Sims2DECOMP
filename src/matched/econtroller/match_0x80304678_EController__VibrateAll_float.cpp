// 0x80304678 EController::VibrateAll(float, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 31,3; fmr f30,f2; lwz 9,0x208(31); fmr f2,f3; fmr f31,f4; li 30,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x208(31); fmr f1,f30; fmr f2,f31; lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 30,1; 0:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"

struct EController {
    void VibrateAll();
};

void EController::VibrateAll() {
}
