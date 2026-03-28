/* global dtor at 0x803287C4 (44 bytes) */

void Init_dtor_803287C4(int flag, unsigned int mask);

void global_dtor_803287C4(void)
{
    Init_dtor_803287C4(0, 0xFFFF);
}
