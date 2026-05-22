// 0x801AE598 E2ETarget::OnSaveGameComplete(bool) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; li 0,0; lis 3,-32705; stw 0,0x284(9); addi 3,3,-2260; stw 0,0xe0(9); li 4,0; li 5,0; li 6,0; li 7,0; bl _s801AE598_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AE598_0();
extern "C" void f_801AE598() {}
