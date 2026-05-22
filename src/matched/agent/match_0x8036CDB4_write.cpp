// 0x8036CDB4 _write (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; addi 0,9,-1; cmplwi 0,1; ble 0f; cmpwi 9,0; li 3,-1; beq 1f; mr 3,9; bl _s8036CDB4_0; b 1f; 0:; mr 3,4; mr 4,5; bl _s8036CDB4_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036CDB4_0();
extern "C" void _s8036CDB4_1();
extern "C" void f_8036CDB4() {}
