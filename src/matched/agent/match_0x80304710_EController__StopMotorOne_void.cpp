// 0x80304710 EController::StopMotorOne(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x208(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lis 9,-32702; li 3,1; lfs f0,-1648(9); stfs f0,0x1dc(31); stfs f0,0x1e4(31); b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80304710() {}
