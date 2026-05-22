// 0x801E9410 GetVar_EYE_connectionStatus::Handler(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; bl _s801E9410_0; lwz 9,-28712(13); cmpwi 3,0; stw 3,0xb0(9); beq 0f; lis 9,-32704; addi 5,9,-30824; b 1f; 0:; lis 9,-32704; addi 5,9,-30820; 1:; lis 4,-32704; mr 3,31; addi 4,4,-30812; crxor 6,6,6; bl _s801E9410_1; lwz 9,-28712(13); li 0,0; stw 0,0xb0(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801E9410_0();
extern "C" void _s801E9410_1();
extern "C" void f_801E9410() {}
