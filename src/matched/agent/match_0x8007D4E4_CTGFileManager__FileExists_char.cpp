// 0x8007D4E4 CTGFileManager::FileExists(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; mfcr 12; stw 0,0x14(1); stw 12,0xc(1); mr 3,4; lis 4,-32707; addi 4,4,26712; bl _s8007D4E4_0; mr. 3,3; mcrf cr4,cr0; beq cr4,0f; bl _s8007D4E4_1; 0:; li 3,1; bne cr4,1f; li 3,0; 1:; lwz 0,0x14(1); lwz 12,0xc(1); mtspr 8,0; mtcrf 8,12; addi 1,1,16"
extern "C" void _s8007D4E4_0();
extern "C" void _s8007D4E4_1();
extern "C" void f_8007D4E4() {}
