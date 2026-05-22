// 0x8012C1F4 cXPersonImpl::IsCarryingDCObject(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x170(9); lwz 9,0x174(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x0(30); li 4,0; lwz 30,0x4(11); lwz 9,0x4(30); lwz 11,0x2bc(9); addi 29,9,1160; lha 3,0x2b8(9); mtspr 8,11; lha 0,0x488(9); add 3,30,3; add 30,30,0; blrl; lwz 0,0x4(29); lha 4,0x4(3); mtspr 8,0; mr 3,30; blrl; lwz 9,0x4(3); lha 0,0x310(9); lwz 9,0x314(9); add 3,3,0; mtspr 8,9; blrl; lha 3,0xa(3); addi 3,3,-35; subfic 3,3,2; li 3,0; adde 3,3,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_8012C1F4() {}
