/* global dtor at 0x80328348 (44 bytes) */

void Init_dtor_80328348(int flag, unsigned int mask);

void global_dtor_80328348(void)
{
    Init_dtor_80328348(0, 0xFFFF);
}
