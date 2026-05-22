// 0x801EBFFC GOLTarget::InstallMapShader(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8c(3); cmpwi 0,0; bne 0f; lis 9,-32704; addi 4,9,-28764; b 1f; 0:; lis 9,-32704; addi 4,9,-28752; 1:; lwz 0,0x94(3); cmpwi 0,1; bne 2f; lwz 0,0x0(3); cmpwi 0,0; beq 3f; lwz 0,0x1c(3); cmpwi 0,0; beq 3f; lwz 6,0x7c(3); lis 5,5096; mr 3,0; ori 5,5,58435; li 7,0; bl _s801EBFFC_0; b 3f; 2:; lwz 0,0x0(3); cmpwi 0,0; beq 3f; lwz 3,0x1c(3); cmpwi 3,0; beq 3f; bl _s801EBFFC_1; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801EBFFC_0();
extern "C" void _s801EBFFC_1();
extern "C" void f_801EBFFC() {}
