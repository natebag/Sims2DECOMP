/* global dtor at 0x803281B0 (44 bytes) */

void Init_dtor_803281B0(int flag, unsigned int mask);

void global_dtor_803281B0(void)
{
    Init_dtor_803281B0(0, 0xFFFF);
}
