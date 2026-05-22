// 0x801F58A0 INVTarget::GetMotiveText(int, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-21508(13); mr 30,3; mr 31,5; cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,31; mr 3,30; bl _s801F58A0_0; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F58A0_0();
extern "C" void f_801F58A0() {}
