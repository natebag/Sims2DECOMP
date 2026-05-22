// 0x80182458 WidgetScreenFormat::IterateScreenLayout(char (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lwz 3,0x0(30); lis 4,-32705; mr 29,5; addi 4,4,-24048; bl _s80182458_0; mr. 3,3; beq 0f; li 3,0; b 2f; 0:; stw 30,0x4(31); cmpwi 29,2; stw 3,0x0(31); bne 1f; stw 3,0xc(31); 1:; mr 3,31; mr 4,29; bl _s80182458_1; lwz 3,0x0(31); xori 3,3,1; subfic 0,3,0; adde 3,0,3; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80182458_0();
extern "C" void _s80182458_1();
extern "C" void f_80182458() {}
