// 0x802D41A8 EString2::Deallocate(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; addi 0,13,-26852; cmpw 31,0; beq 0f; lis 9,-32700; addi 9,9,-4780; cmpw 31,9; beq 0f; bl _s802D41A8_0; mr 4,31; bl _s802D41A8_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D41A8_0();
extern "C" void _s802D41A8_1();
extern "C" void f_802D41A8() {}
