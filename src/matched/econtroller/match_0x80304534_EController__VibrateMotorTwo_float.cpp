// 0x80304534 EController::VibrateMotorTwo(float) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 9,0x208(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 0,0x204(31); cmpwi 0,0; bne 1f; 0:; li 3,0; b 2f; 1:; stfs f31,0x1e0(31); li 3,1; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"

struct EController {
    void VibrateMotorTwo();
};

void EController::VibrateMotorTwo() {
}
