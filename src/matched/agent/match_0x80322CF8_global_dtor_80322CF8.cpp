/* global dtor at 0x80322CF8 (44 bytes) */

void Init_dtor_80322CF8(int flag, unsigned int mask);

void global_dtor_80322CF8(void)
{
    Init_dtor_80322CF8(0, 0xFFFF);
}
