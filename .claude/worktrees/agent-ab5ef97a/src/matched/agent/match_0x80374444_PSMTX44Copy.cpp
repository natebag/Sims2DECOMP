/* PSMTX44Copy - 68 bytes at 0x80374444 */

void PSMTX44Copy(float src[4][4], float dst[4][4]);

__attribute__((naked))
void PSMTX44Copy(float src[4][4], float dst[4][4]) {
    asm volatile(
        ".long 0xE0230000\n"
        ".long 0xF0240000\n"
        ".long 0xE0230008\n"
        ".long 0xF0240008\n"
        ".long 0xE0230010\n"
        ".long 0xF0240010\n"
        ".long 0xE0230018\n"
        ".long 0xF0240018\n"
        ".long 0xE0230020\n"
        ".long 0xF0240020\n"
        ".long 0xE0230028\n"
        ".long 0xF0240028\n"
        ".long 0xE0230030\n"
        ".long 0xF0240030\n"
        ".long 0xE0230038\n"
        ".long 0xF0240038\n"
        "blr\n"
    );
}
