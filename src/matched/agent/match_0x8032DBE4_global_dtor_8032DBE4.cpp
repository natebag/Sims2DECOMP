/* global dtor at 0x8032DBE4 (44 bytes) */

void Init_dtor_8032DBE4(int flag, unsigned int mask);

void global_dtor_8032DBE4(void)
{
    Init_dtor_8032DBE4(0, 0xFFFF);
}
