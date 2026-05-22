// 0x80260FC4 AlarmHandlerForTimeout (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 3,1024; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; bl _s80260FC4_0; addi 3,1,16; bl _s80260FC4_1; addi 3,1,16; bl _s80260FC4_2; lwz 12,-23352(13); li 0,0; cmplwi 12,0; stw 0,-23352(13); beq 0f; mtspr 8,12; li 3,16; blrl; 0:; addi 3,1,16; bl _s80260FC4_3; mr 3,31; bl _s80260FC4_4; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80260FC4_0();
extern "C" void _s80260FC4_1();
extern "C" void _s80260FC4_2();
extern "C" void _s80260FC4_3();
extern "C" void _s80260FC4_4();
extern "C" void f_80260FC4() {}
