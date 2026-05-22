// 0x801113AC ObjSelector::GetFnTable(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x64(31); cmpwi 0,0; bne 3f; bl _s801113AC_0; lwz 0,0x64(31); mr 30,3; cmpw 30,0; beq 2f; cmpwi 30,0; beq 0f; lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; 0:; lwz 11,0x64(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 30,0x64(31); 2:; lwz 3,0x64(31); lwz 4,0x4(31); lwz 9,0x0(3); lha 5,0x7c(31); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,-98; bne 3f; lwz 3,0x64(31); lwz 4,0x38(31); lwz 9,0x0(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; 3:; lwz 3,0x64(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801113AC_0();
extern "C" void f_801113AC() {}
