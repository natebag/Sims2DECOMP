// 0x801C6E5C MMUTarget::OnUpKeyPressed(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xb0(3); cmpwi 0,4; bne 0f; bl _s801C6E5C_0; b 4f; 0:; lwz 0,0x8c(3); cmpwi 0,1; bne 2f; lwz 9,0x9c(3); addi 9,9,-1; cmpwi 9,0; stw 9,0x9c(3); bge 1f; li 0,5; stw 0,0x9c(3); 1:; bl _s801C6E5C_1; b 4f; 2:; cmpwi 0,2; bne 4f; lwz 9,0x98(3); addi 9,9,-1; cmpwi 9,0; stw 9,0x98(3); bge 3f; lwz 9,0xa0(3); addi 9,9,-1; stw 9,0x98(3); 3:; bl _s801C6E5C_2; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C6E5C_0();
extern "C" void _s801C6E5C_1();
extern "C" void _s801C6E5C_2();
extern "C" void f_801C6E5C() {}
