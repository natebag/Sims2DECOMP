/* global dtor at 0x803255F0 (44 bytes) */

void Init_dtor_803255F0(int flag, unsigned int mask);

void global_dtor_803255F0(void)
{
    Init_dtor_803255F0(0, 0xFFFF);
}
