// 0x8034D760 ax_drop_voice_callback(void (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32690; mr 30,3; addi 28,9,-19244; li 29,0; li 27,0; li 31,0; 0:; lwzx 0,31,28; addi 29,29,1; mr 3,30; cmpw 0,30; bne 1f; bl _s8034D760_0; stwx 27,31,28; 1:; addi 31,31,68; cmplwi 29,61; ble 0b; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8034D760_0();
extern "C" void f_8034D760() {}
