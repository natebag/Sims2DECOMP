/* global dtor at 0x803284CC (44 bytes) */

void Init_dtor_803284CC(int flag, unsigned int mask);

void global_dtor_803284CC(void)
{
    Init_dtor_803284CC(0, 0xFFFF);
}
