// 0x8032EB08 EventAlarmHandler(OSAlarm (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s8032EB08_0; li 31,1; cmpwi 3,0; bne 0f; li 31,0; 0:; lis 3,-32692; addi 3,3,18432; bl _s8032EB08_1; lwz 9,-26568(13); cmpwi 9,0; ble 1f; addi 0,9,-10; cmpwi 0,0; stw 0,-26568(13); bge 1f; li 0,0; stw 0,-26568(13); 1:; mr 3,31; bl _s8032EB08_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8032EB08_0();
extern "C" void _s8032EB08_1();
extern "C" void _s8032EB08_2();
extern "C" void f_8032EB08() {}
