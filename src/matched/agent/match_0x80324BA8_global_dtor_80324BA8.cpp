/* global dtor at 0x80324BA8 (44 bytes) */

void Init_dtor_80324BA8(int flag, unsigned int mask);

void global_dtor_80324BA8(void)
{
    Init_dtor_80324BA8(0, 0xFFFF);
}
