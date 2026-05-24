// 0x802FBFEC ESubModelShader::CreateRCPrimitive(unsigned (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); lwz 0,0x10(3); mr 8,5; mr 31,6; cmplwi 4,2; rlwinm 10,0,26,31,31; ble 5f; andi. 9,0,32; beq 2f; andi. 9,0,16; beq 0f; lwz 11,0x70(8); lwz 4,0x20(31); lha 3,0x308(11); stw 10,0x8(1); add 3,8,3; lwz 10,0x8(31); lwz 0,0x30c(11); b 1f; 0:; lwz 11,0x70(8); lwz 4,0x20(31); lha 3,0x2f8(11); stw 10,0x8(1); add 3,8,3; lwz 10,0x8(31); lwz 0,0x2fc(11); 1:; lwz 5,0x1c(31); lwz 6,0x18(31); mtspr 8,0; lwz 7,0x0(31); lwz 8,0x4(31); lwz 9,0xc(31); blrl; b 4f; 2:; andi. 9,0,16; beq 3f; lwz 9,0x70(8); lwz 4,0x18(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,8,3; lwz 5,0x0(31); lwz 6,0x4(31); mtspr 8,0; lwz 7,0xc(31); lwz 8,0x8(31); lwz 9,0x10(31); blrl; b 4f; 3:; lwz 9,0x70(8); lwz 4,0x18(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,8,3; lwz 5,0x0(31); lwz 6,0x4(31); mtspr 8,0; lwz 7,0xc(31); lwz 8,0x8(31); lwz 9,0x10(31); blrl; 4:; lwz 3,0x18(31); addi 3,3,-2; b 6f; 5:; li 3,0; 6:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

struct ESubModelShader {
    void CreateRCPrimitive();
};

void ESubModelShader::CreateRCPrimitive() {
}
