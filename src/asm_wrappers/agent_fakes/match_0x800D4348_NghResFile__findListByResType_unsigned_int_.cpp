/* NghResFile::findListByResType(unsigned int) at 0x800D4348 (148B) */

struct NghResFile { void findListByResType(); };

__attribute__((naked))
void NghResFile::findListByResType() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C9F2378\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7FE3FB78\n"
        ".long 0x3BA00000\n"
        ".long 0x4BFFF519\n"
        ".long 0x7C631B79\n"
        ".long 0x4180000C\n"
        ".long 0x813E0138\n"
        ".long 0x48000044\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFFF539\n"
        ".long 0x7C631B79\n"
        ".long 0x41800020\n"
        ".long 0x801E0024\n"
        ".long 0x397E013C\n"
        ".long 0x546A103A\n"
        ".long 0x5400103A\n"
        ".long 0x7D2B002E\n"
        ".long 0x7FA95214\n"
        ".long 0x48000020\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFFF545\n"
        ".long 0x7C631B79\n"
        ".long 0x41800010\n"
        ".long 0x813E017C\n"
        ".long 0x5460103A\n"
        ".long 0x7FA90214\n"
        ".long 0x7FA3EB78\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
