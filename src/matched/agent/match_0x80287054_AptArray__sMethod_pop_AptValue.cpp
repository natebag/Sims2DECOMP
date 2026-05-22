// 0x80287054 AptArray::sMethod_pop(AptValue (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 11,0; lwz 9,0x0(31); lwz 3,-22936(13); rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 1f; lwz 4,0x2c(31); cmpwi 4,0; ble 1f; addi 4,4,-1; mr 3,31; bl _s80287054_0; lwz 9,0x2c(31); li 0,0; lwz 10,0x24(31); addi 9,9,-1; rlwinm 11,9,2,0,29; stw 9,0x2c(31); stwx 0,11,10; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80287054_0();
extern "C" void f_80287054() {}
