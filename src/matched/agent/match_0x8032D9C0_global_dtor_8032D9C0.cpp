/* global dtor at 0x8032D9C0 (44 bytes) */

void Init_dtor_8032D9C0(int flag, unsigned int mask);

void global_dtor_8032D9C0(void)
{
    Init_dtor_8032D9C0(0, 0xFFFF);
}
