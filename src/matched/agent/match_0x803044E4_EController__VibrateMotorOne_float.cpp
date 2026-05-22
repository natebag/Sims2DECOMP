// 0x803044E4 EController::VibrateMotorOne(float, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 0,0x204(11); cmpwi 0,0; beq 0f; stfs f2,0x1e4(11); lwz 9,0x208(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_803044E4() {}
