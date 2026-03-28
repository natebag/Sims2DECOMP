/* IconGroup::GetBalloonSpriteID(IconGroup::BalloonType) at 0x800BCC68 (156B) */

struct IconGroup { void GetBalloonSpriteID(); };

__attribute__((naked))
void IconGroup::GetBalloonSpriteID() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10018\n"
        ".long 0x90010024\n"
        ".long 0x7C7F1B78\n"
        ".long 0x3BC00000\n"
        ".long 0x38610008\n"
        ".long 0x4BFFFD8D\n"
        ".long 0x38610008\n"
        ".long 0x38800001\n"
        ".long 0x4BFFFDA5\n"
        ".long 0x2C1F0001\n"
        ".long 0x41820038\n"
        ".long 0x41810010\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820014\n"
        ".long 0x48000038\n"
        ".long 0x2C1F0002\n"
        ".long 0x41820014\n"
        ".long 0x4800002C\n"
        ".long 0x38610008\n"
        ".long 0x38800000\n"
        ".long 0x48000018\n"
        ".long 0x38610008\n"
        ".long 0x38800002\n"
        ".long 0x4800000C\n"
        ".long 0x38610008\n"
        ".long 0x38800001\n"
        ".long 0x4BFFFE2D\n"
        ".long 0x7C7E1B78\n"
        ".long 0x38610008\n"
        ".long 0x38800002\n"
        ".long 0x4BFFFDA5\n"
        ".long 0x7FC3F378\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10018\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
