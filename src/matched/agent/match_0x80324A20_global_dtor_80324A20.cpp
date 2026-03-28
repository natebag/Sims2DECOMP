/* global dtor at 0x80324A20 (44 bytes) */

void Init_dtor_80324A20(int flag, unsigned int mask);

void global_dtor_80324A20(void)
{
    Init_dtor_80324A20(0, 0xFFFF);
}
