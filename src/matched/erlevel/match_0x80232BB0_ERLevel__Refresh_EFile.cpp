// 0x80232BB0 ERLevel::Refresh(EFile (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr. 31,4; beq 8f; addis 28,29,3; bl _s80232BB0_0; mr 3,29; bl _s80232BB0_1; mr 3,31; bl _s80232BB0_2; mr 27,3; addis 9,27,3; lwz 0,-15688(9); addic. 31,0,-1; blt 1f; rlwinm 9,31,2,0,29; li 26,0; addis 9,9,3; addi 9,9,-23880; add 30,9,27; 0:; lwz 9,0x0(30); mr 3,29; stw 26,0x4(9); lwz 4,0x0(30); bl _s80232BB0_3; lwz 4,0x0(30); mr 3,29; bl _s80232BB0_4; lwz 9,0x0(30); addic. 31,31,-1; addi 30,30,-4; lwz 0,0x5c(9); ori 0,0,8192; stw 0,0x5c(9); bge 0b; 1:; addis 8,27,3; li 31,0; lwz 0,-25216(8); mr 6,8; cmpw 31,0; bge 3f; mr 7,28; li 5,0; addi 10,28,-25212; li 11,0; 2:; addi 9,8,-25212; addi 31,31,1; lwzx 0,9,11; stw 0,0x0(10); stwx 5,9,11; addi 10,10,4; addi 11,11,4; lwz 9,-25216(7); addi 9,9,1; stw 9,-25216(7); lwz 0,-25216(8); cmpw 31,0; blt 2b; 3:; lwz 0,-25012(6); li 31,0; mr 7,6; cmpw 31,0; bge 5f; mr 8,28; li 5,0; addi 10,28,-25008; li 11,0; 4:; addi 9,7,-25008; addi 31,31,1; lwzx 0,9,11; stw 0,0x0(10); stwx 5,9,11; addi 10,10,4; addi 11,11,4; lwz 9,-25012(8); addi 9,9,1; stw 9,-25012(8); lwz 0,-25012(7); cmpw 31,0; blt 4b; 5:; lwz 0,-24608(28); li 31,0; mr 10,28; cmpw 31,0; bge 7f; li 7,0; addi 11,6,-24604; li 8,0; 6:; lwz 0,0x0(11); addi 9,10,-24604; addi 31,31,1; stwx 0,9,8; stw 7,0x0(11); addi 8,8,4; addi 11,11,4; lwz 9,-24608(10); addi 9,9,1; cmpw 31,9; stw 9,-24608(10); blt 6b; 7:; li 30,0; mr 3,27; stw 30,-15688(6); stw 30,-25216(6); stw 30,-25012(6); stw 30,-24608(6); bl _s80232BB0_5; stw 30,-25232(28); 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80232BB0_0();
extern "C" void _s80232BB0_1();
extern "C" void _s80232BB0_2();
extern "C" void _s80232BB0_3();
extern "C" void _s80232BB0_4();
extern "C" void _s80232BB0_5();

struct ERLevel {
    void Refresh_EFile();
};

void ERLevel::Refresh_EFile() {
}
