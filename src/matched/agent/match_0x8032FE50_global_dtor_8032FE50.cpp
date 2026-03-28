/* global dtor at 0x8032FE50 (44 bytes) */

void Init_dtor_8032FE50(int flag, unsigned int mask);

void global_dtor_8032FE50(void)
{
    Init_dtor_8032FE50(0, 0xFFFF);
}
