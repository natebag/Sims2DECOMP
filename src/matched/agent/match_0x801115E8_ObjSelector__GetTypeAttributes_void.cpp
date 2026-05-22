// 0x801115E8 ObjSelector::GetTypeAttributes(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x38(3); lwz 4,0xb8(9); cmpwi 4,0; bne 0f; lwz 4,0x1c(9); 0:; lwz 3,0x50(3); lwz 9,0x0(3); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 1f; lwz 3,0x8(3); b 2f; 1:; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801115E8() {}
