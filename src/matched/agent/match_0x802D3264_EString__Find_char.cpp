// 0x802D3264 EString::Find(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); lbz 0,0x0(3); cmpwi 0,0; bne 0f; li 3,-1; b 2f; 0:; add 3,3,5; bl _s802D3264_0; mr. 3,3; beq 1f; lwz 0,0x0(31); subf 3,0,3; b 2f; 1:; li 3,-1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D3264_0();
extern "C" void f_802D3264() {}
