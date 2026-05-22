// 0x80037A9C EyeToyClient::AcquireRenderSurface(int, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 0,0x3c(1); addi 10,1,8; li 0,64; stw 0,0x4(10); lis 9,-32707; stw 0,0x8(1); li 11,1; lfs f0,0x164c(9); li 0,3; stw 0,0x8(10); addi 8,1,20; stw 11,0x1c(10); li 7,0; stw 11,0x18(10); stfs f0,0x28(1); stfs f0,0x30(1); stfs f0,0x2c(1); lwz 9,0x28(1); lwz 11,0x2c(1); lwz 0,0x30(1); stw 9,0x14(1); stw 11,0x4(8); stw 0,0x8(8); stw 3,0x8(1); stw 4,0xc(1); stw 7,0x10(1); mr 4,10; stw 7,0x20(1); lwz 11,-26392(13); lwz 9,0x0(11); lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x3c(1); mtspr 8,0; addi 1,1,56"
extern "C" void f_80037A9C() {}
