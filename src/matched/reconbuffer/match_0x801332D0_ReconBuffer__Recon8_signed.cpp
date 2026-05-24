// 0x801332D0 ReconBuffer::Recon8(signed (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,3; mr 29,4; lwz 0,0x18(30); mr 31,5; cmpwi 0,0; beq 3f; lwz 9,0xc(30); addi 9,9,-1; cmplwi 9,1; bgt 1f; mr 0,31; cmpwi 0,0; addi 31,31,-1; ble 8f; lis 28,-32696; 0:; lbz 0,0x0(29); mr 3,30; addi 4,1,8; addi 5,28,26664; extsb 0,0; addi 29,29,1; stw 0,0x8(1); bl _s801332D0_0; mr 0,31; cmpwi 0,0; addi 31,31,-1; bgt 0b; b 8f; 1:; mr 0,31; cmpwi 0,0; addi 31,31,-1; ble 8f; addi 28,1,12; lis 27,-32696; 2:; mr 3,30; mr 4,28; addi 5,27,26664; bl _s801332D0_1; lbz 9,0x3(28); mr 0,31; cmpwi 0,0; addi 31,31,-1; stb 9,0x0(29); addi 29,29,1; bgt 2b; b 8f; 3:; lwz 0,0xc(30); cmpwi 0,2; bne 4f; lwz 0,0x8(30); add 0,0,31; stw 0,0x8(30); b 8f; 4:; cmpwi 0,0; bne 5f; lwz 9,0x0(30); mr 11,29; lwz 0,0x8(30); add 4,9,0; b 6f; 5:; lwz 9,0x0(30); mr 4,29; lwz 0,0x8(30); add 11,9,0; 6:; mr 0,31; cmpwi 0,0; addi 31,31,-1; ble 8f; 7:; lbz 9,0x0(4); mr 0,31; cmpwi 0,0; addi 4,4,1; stb 9,0x0(11); addi 31,31,-1; addi 11,11,1; lwz 9,0x8(30); addi 9,9,1; stw 9,0x8(30); bgt 7b; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s801332D0_0();
extern "C" void _s801332D0_1();

struct ReconBuffer {
    void Recon8_signed();
};

void ReconBuffer::Recon8_signed() {
}
