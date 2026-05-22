// 0x801E9350 GetVar_SaveRequired::Handler(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-28712(13); mr 3,4; li 11,0; lwz 0,0x88(9); cmpwi 0,0; ble 0f; lwz 0,0xb0(9); subfic 9,0,0; adde 11,9,0; 0:; cmpwi 11,0; beq 1f; lis 9,-32704; addi 5,9,-30820; b 2f; 1:; lis 9,-32704; addi 5,9,-30824; 2:; lis 4,-32704; addi 4,4,-30812; crxor 6,6,6; bl _s801E9350_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801E9350_0();
extern "C" void f_801E9350() {}
