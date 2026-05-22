// 0x802551BC OSClearStack (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm 0,3,16,8,15; rlwimi 0,3,24,0,7; stwu 1,-24(1); rlwimi 0,3,8,16,23; stw 31,0x14(1); mr 31,0; rlwimi 31,3,0,24,31; bl _s802551BC_0; lis 4,-32768; lwz 5,0xe4(4); addi 4,3,3; lwz 5,0x308(5); addi 5,5,4; cmplw 5,3; subf 4,5,4; rlwinm 4,4,30,2,31; bge 3f; rlwinm. 0,4,29,3,31; mtspr 9,0; beq 1f; 0:; stw 31,0x0(5); stw 31,0x4(5); stw 31,0x8(5); stw 31,0xc(5); stw 31,0x10(5); stw 31,0x14(5); stw 31,0x18(5); stw 31,0x1c(5); addi 5,5,32; bdnz 0b; andi. 4,4,7; beq 3f; 1:; mtspr 9,4; 2:; stw 31,0x0(5); addi 5,5,4; bdnz 2b; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802551BC_0();
extern "C" void f_802551BC() {}
