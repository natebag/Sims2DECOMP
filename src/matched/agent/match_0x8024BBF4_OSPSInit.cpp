// 0x8024BBF4 __OSPSInit (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8024BBF4_0; oris 3,3,40960; bl _s8024BBF4_1; bl _s8024BBF4_2; sync; li 3,0; mtspr 912,3; mtspr 913,3; mtspr 914,3; mtspr 915,3; mtspr 916,3; mtspr 917,3; mtspr 918,3; mtspr 919,3; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024BBF4_0();
extern "C" void _s8024BBF4_1();
extern "C" void _s8024BBF4_2();
extern "C" void f_8024BBF4() {}
