// 0x801F67F0 INVTarget::GetOnMsgInvInventoryCount(char (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 5,0xd4(3); lis 9,-32704; mr 3,4; addi 4,9,-30836; crxor 6,6,6; bl _s801F67F0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F67F0_0();
extern "C" void f_801F67F0() {}
