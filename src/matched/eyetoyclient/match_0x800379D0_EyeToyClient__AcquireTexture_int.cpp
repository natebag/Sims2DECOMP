// 0x800379D0 EyeToyClient::AcquireTexture(int, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); li 0,0; addi 9,1,8; stw 0,0x8(1); li 10,32; stb 10,0x1a(9); li 8,64; stb 0,0x19(9); li 11,1; stb 0,0x1b(9); stb 11,0x18(9); sth 8,0x10(9); stw 0,0x1c(9); stw 0,0x4(9); stw 0,0x8(9); sth 8,0x12(9); sth 0,0x14(9); sth 0,0x16(9); sth 3,0x18(1); sth 4,0x1a(1); stb 5,0x22(1); mr 4,9; lwz 11,-26392(13); lwz 9,0x0(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"

struct EyeToyClient {
    void AcquireTexture();
};

void EyeToyClient::AcquireTexture() {
}
