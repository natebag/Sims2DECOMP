// 0x801E93BC GetVar_ImageSlotsAvail::Handler(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-28712(13); mr 3,4; lwz 0,0x84(9); cmpwi 0,0; beq 0f; lis 9,-32704; addi 5,9,-30820; b 1f; 0:; lis 9,-32704; addi 5,9,-30824; 1:; lis 4,-32704; addi 4,4,-30812; crxor 6,6,6; bl _s801E93BC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801E93BC_0();
extern "C" void f_801E93BC() {}
