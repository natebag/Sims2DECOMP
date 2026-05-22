// 0x801B3388 FAMTarget::GetLotForFamily(Family (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 9,0x0(4); lha 3,0xa8(9); lwz 0,0xac(9); add 3,4,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801B3388() {}
