// 0x80059C14 EyeToyClient::RestoreDefaults(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; beq 0f; li 4,3; bl _s80059C14_0; 0:; stw 30,0x164(31); mr 3,31; bl _s80059C14_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80059C14_0();
extern "C" void _s80059C14_1();
extern "C" void f_80059C14() {}
