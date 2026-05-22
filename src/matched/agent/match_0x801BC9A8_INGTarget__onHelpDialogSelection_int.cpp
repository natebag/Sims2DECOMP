// 0x801BC9A8 INGTarget::onHelpDialogSelection(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 9,0x134(11); addi 9,9,1; cmplwi 9,1; stw 9,0x134(11); bgt 0f; lwz 9,0x80(11); lis 4,-32705; lis 5,-32705; addi 4,4,5804; lha 3,0x10(9); addi 5,5,6640; lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 0,0; stw 0,0x134(11); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801BC9A8() {}
