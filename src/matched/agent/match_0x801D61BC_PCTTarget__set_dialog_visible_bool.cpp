// 0x801D61BC PCTTarget::set_dialog_visible(bool) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); cmpwi 4,0; beq 0f; lis 9,-32705; addi 9,9,-5288; b 1f; 0:; lis 9,-32705; addi 9,9,-5284; 1:; lis 3,-32705; stw 9,0x8(1); addi 3,3,17232; li 4,0; li 5,0; li 6,1; addi 7,1,8; bl _s801D61BC_0; li 3,1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s801D61BC_0();
extern "C" void f_801D61BC() {}
