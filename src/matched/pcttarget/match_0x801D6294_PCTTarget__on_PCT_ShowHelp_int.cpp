// 0x801D6294 PCTTarget::on_PCT_ShowHelp(int) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xb0(3); lwz 10,0xa8(3); mulli 11,0,20; add 9,10,11; cmpwi 9,0; bne 1f; 0:; li 3,0; b 7f; 1:; lwz 0,0xec(3); cmpwi 0,0; beq 3f; lwz 0,0x90(3); cmpwi 0,1; bne 2f; lwz 4,0x84(3); lis 5,-32705; addi 5,5,18328; b 6f; 2:; lwz 4,0x84(3); lis 5,-32705; addi 5,5,18348; b 6f; 3:; lwzx 0,10,11; cmpwi 0,1; bne 4f; lwz 4,0x84(3); lis 5,-32705; addi 5,5,18364; b 6f; 4:; ble 0b; cmpwi 0,4; bgt 0b; lwz 0,0xe8(3); cmpwi 0,0; beq 5f; lwz 4,0x84(3); lis 5,-32705; addi 5,5,18380; b 6f; 5:; lwz 4,0x84(3); lis 5,-32705; addi 5,5,18396; 6:; addi 3,3,380; li 6,0; li 7,0; li 8,0; bl _s801D6294_0; li 3,1; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801D6294_0();

struct PCTTarget {
    void on_PCT_ShowHelp();
};

void PCTTarget::on_PCT_ShowHelp() {
}
