/* global dtor at 0x80322334 (44 bytes) */

void Init_dtor_80322334(int flag, unsigned int mask);

void global_dtor_80322334(void)
{
    Init_dtor_80322334(0, 0xFFFF);
}
