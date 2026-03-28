/* global dtor at 0x803350DC (44 bytes) */

void Init_dtor_803350DC(int flag, unsigned int mask);

void global_dtor_803350DC(void)
{
    Init_dtor_803350DC(0, 0xFFFF);
}
