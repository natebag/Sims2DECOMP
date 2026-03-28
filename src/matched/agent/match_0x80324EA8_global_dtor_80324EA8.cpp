/* global dtor at 0x80324EA8 (44 bytes) */

void Init_dtor_80324EA8(int flag, unsigned int mask);

void global_dtor_80324EA8(void)
{
    Init_dtor_80324EA8(0, 0xFFFF);
}
