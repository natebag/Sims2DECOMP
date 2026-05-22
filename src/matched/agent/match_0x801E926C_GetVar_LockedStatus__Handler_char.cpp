// 0x801E926C GetVar_LockedStatus::Handler(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xc(3); mr 3,4; cmpwi 0,0; beq 0f; lis 9,-32704; addi 4,9,-30824; b 1f; 0:; lis 9,-32704; addi 4,9,-30820; 1:; bl _s801E926C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801E926C_0();
extern "C" void f_801E926C() {}
