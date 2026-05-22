// 0x8017D2B0 UIReflow::SetFocus(UIScreenID) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stw 0,0x8c(1); lwz 0,0x4(3); cmpwi 0,0; bne 0f; lis 9,-32697; mr 5,4; lwz 3,0x5f10(9); addi 4,1,8; bl _s8017D2B0_0; cmpwi 3,0; beq 0f; lis 4,-32706; lis 8,-32706; lwz 3,-25136(13); addi 4,4,14152; addi 8,8,14160; li 5,0; li 6,0; li 7,2; addi 9,1,8; crxor 6,6,6; bl _s8017D2B0_1; 0:; lwz 0,0x8c(1); mtspr 8,0; addi 1,1,136"
extern "C" void _s8017D2B0_0();
extern "C" void _s8017D2B0_1();
extern "C" void f_8017D2B0() {}
