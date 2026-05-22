// 0x801BC228 INGTarget::set_done_button_state(bool) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,0; lwz 3,-25136(13); beq 0f; lis 9,-32705; addi 8,9,-5288; b 1f; 0:; lis 9,-32705; addi 8,9,-5284; 1:; lis 4,-32705; li 5,0; addi 4,4,6596; li 6,0; li 7,1; crxor 6,6,6; bl _s801BC228_0; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801BC228_0();
extern "C" void f_801BC228() {}
