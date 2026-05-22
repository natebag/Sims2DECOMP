// 0x8034E64C ENGCAudioStreamer::AnyIsActive(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8034E64C_0; lis 9,-32690; addi 9,9,-14064; addi 11,9,120; 0:; lwz 0,0x0(9); addi 9,9,120; cmpwi 0,0; beq 1f; bl _s8034E64C_1; li 3,1; b 2f; 1:; cmplw 9,11; ble 0b; bl _s8034E64C_2; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8034E64C_0();
extern "C" void _s8034E64C_1();
extern "C" void _s8034E64C_2();
extern "C" void f_8034E64C() {}
