// 0x80267384 AIInit (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; lwz 0,-23120(13); cmpwi 0,1; beq 0f; lwz 3,-27624(13); bl _s80267384_0; lis 3,-32768; lwz 0,0xf8(3); lis 3,17180; lis 4,1; rlwinm 0,0,30,2,31; addi 3,3,-8573; mulhwu 0,3,0; rlwinm 9,0,17,15,31; addi 5,4,-23512; addi 3,4,-23536; addi 0,4,-2536; lis 4,4194; mullw 7,9,5; addi 10,4,19923; mullw 5,9,3; mullw 4,9,0; mulli 8,9,31524; mulli 3,9,3000; mulhwu 8,10,8; mulhwu 7,10,7; mulhwu 5,10,5; mulhwu 4,10,4; mulhwu 3,10,3; rlwinm 8,8,23,9,31; rlwinm 7,7,23,9,31; stw 8,-23108(13); rlwinm 5,5,23,9,31; rlwinm 4,4,23,9,31; stw 7,-23100(13); li 31,0; rlwinm 3,3,23,9,31; stw 5,-23092(13); lis 6,-13312; stw 3,-23076(13); li 3,1; lwz 0,0x6c00(6); stw 4,-23084(13); rlwinm 0,0,0,27,25; ori 0,0,32; stw 31,-23112(13); stw 31,-23104(13); stw 31,-23096(13); stw 31,-23088(13); stw 31,-23080(13); lwz 5,0x6c04(6); stw 0,0x6c00(6); rlwinm 0,5,0,24,15; ori 0,0,0; stw 0,0x6c04(6); lwz 0,0x6c04(6); rlwinm 0,0,0,0,23; ori 0,0,0; stw 0,0x6c04(6); stw 31,0x6c0c(6); bl _s80267384_1; li 3,0; bl _s80267384_2; lis 3,-32730; stw 31,-23136(13); addi 4,3,30072; stw 31,-23132(13); li 3,5; stw 30,-23128(13); bl _s80267384_3; lis 3,1024; bl _s80267384_4; lis 3,-32730; addi 4,3,29948; li 3,8; bl _s80267384_5; lis 3,128; bl _s80267384_6; li 0,1; stw 0,-23120(13); 0:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80267384_0();
extern "C" void _s80267384_1();
extern "C" void _s80267384_2();
extern "C" void _s80267384_3();
extern "C" void _s80267384_4();
extern "C" void _s80267384_5();
extern "C" void _s80267384_6();
extern "C" void f_80267384() {}
