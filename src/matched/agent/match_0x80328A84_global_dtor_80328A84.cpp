/* global dtor at 0x80328A84 (44 bytes) */

void Init_dtor_80328A84(int flag, unsigned int mask);

void global_dtor_80328A84(void)
{
    Init_dtor_80328A84(0, 0xFFFF);
}
