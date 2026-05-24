// 0x802B05B8 AptValue::toFloat(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,0x0(3); andis. 9,0,2048; bne 0f; lis 9,-32703; lfs f1,0x1f20(9); b 10f; 0:; rlwinm 0,0,0,25,31; cmpwi 0,6; beq 6f; bgt 1f; cmpwi 0,1; beq 2f; cmpwi 0,5; beq 4f; b 7f; 1:; cmpwi 0,7; beq 5f; cmpwi 0,42; bne 7f; 2:; lwz 0,0x0(3); mr 9,3; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 3f; lwz 9,0x24(3); 3:; lwz 3,0xc(9); addi 3,3,8; bl _s802B05B8_0; b 10f; 4:; lwz 0,0xc(3); cmpwi 0,0; bne 8f; b 9f; 5:; lwz 0,0xc(3); lis 10,17200; lis 11,-32703; xoris 0,0,32768; lfd f0,0x1f28(11); stw 0,0xc(1); stw 10,0x8(1); lfd f1,0x8(1); fsub f1,f1,f0; frsp f1,f1; b 10f; 6:; lfs f1,0xc(3); b 10f; 7:; lwz 0,-22936(13); cmpw 3,0; beq 9f; 8:; lis 9,-32703; lfs f1,0x1f24(9); b 10f; 9:; lis 9,-32703; lfs f1,0x1f20(9); 10:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s802B05B8_0();

struct AptValue {
    void toFloat();
};

void AptValue::toFloat() {
}
