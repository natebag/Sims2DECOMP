// 0x8026BC9C AptGetMouseOverSpriteName (16b)
// FLAGS: -fno-schedule-insns

extern char gAptMouseOverSpriteName[];

void AptGetMouseOverSpriteName(char *dst) {
    *dst = gAptMouseOverSpriteName[0];
}
