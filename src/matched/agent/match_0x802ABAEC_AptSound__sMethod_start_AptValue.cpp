// 0x802ABAEC AptSound::sMethod_start(AptValue (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; li 10,0; lwz 9,0x0(11); rlwinm 0,9,0,25,31; cmpwi 0,21; bne 0f; rlwinm 10,9,5,31,31; 0:; cmpwi 10,0; beq 1f; lwz 3,0x28(11); cmpwi 3,0; beq 1f; lis 9,-32694; lwz 4,0x2c(11); lwz 0,-16196(9); mtspr 8,0; blrl; 1:; lwz 3,-22936(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802ABAEC() {}
