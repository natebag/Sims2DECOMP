// 0x8013579C iResFile::GetLanguage(Memory::HandleNode (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 9,0xc(3); addi 5,1,8; lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void f_8013579C() {}
