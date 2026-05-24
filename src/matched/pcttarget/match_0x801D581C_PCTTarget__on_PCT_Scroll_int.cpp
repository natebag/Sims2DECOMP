// 0x801D581C PCTTarget::on_PCT_Scroll(int) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,2; beq 6f; bgt 0f; cmpwi 4,1; beq 1f; b 5f; 0:; cmpwi 4,3; beq 2f; cmpwi 4,4; beq 6f; b 5f; 1:; lwz 4,0xb8(31); mr 3,31; addi 4,4,-6; bl _s801D581C_0; cmpwi 3,0; blt 6f; lwz 9,0xb4(31); mr 3,31; addi 9,9,-1; b 4f; 2:; lwz 4,0xb8(31); mr 3,31; addi 4,4,6; bl _s801D581C_1; lwz 9,0xc0(31); lis 0,-21846; ori 0,0,43691; li 10,1; mulhwu 11,9,0; rlwinm 0,11,30,2,31; mulli 0,0,6; cmpw 9,0; bne 3f; li 10,0; 3:; rlwinm 0,11,30,2,31; add 0,0,10; mulli 9,0,6; cmplw 3,9; bge 6f; lwz 9,0xb4(31); mr 3,31; addi 9,9,1; 4:; stw 9,0xb4(31); bl _s801D581C_2; mr 3,31; bl _s801D581C_3; b 6f; 5:; li 3,0; b 7f; 6:; li 3,1; 7:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801D581C_0();
extern "C" void _s801D581C_1();
extern "C" void _s801D581C_2();
extern "C" void _s801D581C_3();

struct PCTTarget {
    void on_PCT_Scroll();
};

void PCTTarget::on_PCT_Scroll() {
}
