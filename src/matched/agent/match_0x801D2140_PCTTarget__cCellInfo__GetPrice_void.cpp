// 0x801D2140 PCTTarget::cCellInfo::GetPrice(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(3); cmpwi 0,2; beq 4f; bgt 0f; cmpwi 0,0; beq 6f; cmpwi 0,1; beq 1f; b 6f; 0:; cmpwi 0,3; beq 5f; cmpwi 0,4; beq 5f; b 6f; 1:; lwz 3,0x14(3); cmpwi 3,0; beq 6f; bl _s801D2140_0; mr. 3,3; bne 2f; li 3,0; b 3f; 2:; lwz 3,0x38(3); 3:; cmpwi 3,0; beq 6f; lha 3,0x24(3); b 7f; 4:; lwz 3,0x14(3); cmpwi 3,0; beq 6f; lwz 3,0x4(3); b 7f; 5:; lwz 3,0x14(3); cmpwi 3,0; beq 6f; lwz 3,0x0(3); b 7f; 6:; li 3,0; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D2140_0();
extern "C" void f_801D2140() {}
