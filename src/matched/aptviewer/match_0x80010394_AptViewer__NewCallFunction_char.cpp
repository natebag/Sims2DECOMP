// 0x80010394 AptViewer::NewCallFunction(char (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stw 0,0xac(1); lis 12,1280; addi 0,1,176; addi 11,1,8; stw 0,0x9c(1); stw 11,0xa0(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 12,0x98(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; lwz 0,0x350(3); mr 8,7; cmpwi 0,0; beq 7f; addi 9,1,152; addi 11,1,136; lwz 10,0x8(9); li 7,0; lwz 0,0x4(9); cmpw 7,8; stw 12,0x88(1); stw 10,0x8(11); stw 0,0x4(11); bge 6f; li 0,5; li 12,8; mtspr 9,0; addi 10,1,112; 1:; lbz 11,0x88(1); extsb 9,11; addi 0,9,1; cmplwi 0,8; bgt 2f; lwz 0,0x90(1); rlwinm 9,9,2,0,29; addi 11,11,1; add 9,0,9; stb 11,0x88(1); b 5f; 2:; cmpwi 9,7; bgt 3f; lwz 9,0x8c(1); stb 12,0x88(1); b 4f; 3:; lwz 9,0x8c(1); 4:; addi 0,9,4; stw 0,0x8c(1); 5:; lwz 0,0x0(9); addi 7,7,1; cmpw 7,8; stw 0,0x0(10); addi 10,10,4; bge 6f; bdnz 1b; 6:; addi 8,1,112; bl _s80010394_0; 7:; lwz 0,0xac(1); mtspr 8,0; addi 1,1,168"

extern "C" void _s80010394_0();

struct AptViewer {
    void NewCallFunction();
};

void AptViewer::NewCallFunction() {
}
