// 0x801F66B8 INVTarget::GetOnMsgInvBackExitReset(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; bl _s801F66B8_0; b 1f; 0:; lis 9,-32704; lhz 0,-30824(9); sth 0,0x0(4); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F66B8_0();
extern "C" void f_801F66B8() {}
