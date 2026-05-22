// 0x8025088C OSSearchModule (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,0; bne 0f; li 3,0; blr; 0:; lis 6,-32768; lwz 8,0x30c8(6); b 7f; 1:; lwz 0,0xc(8); li 10,0; lwz 9,0x10(8); cmplwi 0,0; mtspr 9,0; ble 6f; 2:; lwz 7,0x4(9); cmplwi 7,0; beq 5f; lwz 0,0x0(9); rlwinm 6,0,0,0,30; cmplw 6,3; bgt 5f; add 0,6,7; cmplw 3,0; bge 5f; cmplwi 4,0; beq 3f; stw 10,0x0(4); 3:; cmplwi 5,0; beq 4f; subf 0,6,3; stw 0,0x0(5); 4:; mr 3,8; blr; 5:; addi 9,9,8; addi 10,10,1; bdnz 2b; 6:; lwz 8,0x4(8); 7:; cmplwi 8,0; bne 1b; li 3,0"
extern "C" void f_8025088C() {}
