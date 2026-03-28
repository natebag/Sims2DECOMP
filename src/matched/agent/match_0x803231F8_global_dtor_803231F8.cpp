/* global dtor at 0x803231F8 (44 bytes) */

void Init_dtor_803231F8(int flag, unsigned int mask);

void global_dtor_803231F8(void)
{
    Init_dtor_803231F8(0, 0xFFFF);
}
