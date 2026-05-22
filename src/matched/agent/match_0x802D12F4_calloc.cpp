// 0x802D12F4 calloc (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mullw 30,3,4; bl _s802D12F4_0; li 5,0; mr 4,30; bl _s802D12F4_1; mr. 31,3; beq 0f; mr 5,30; mr 3,31; li 4,0; bl _s802D12F4_2; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D12F4_0();
extern "C" void _s802D12F4_1();
extern "C" void _s802D12F4_2();
extern "C" void f_802D12F4() {}
