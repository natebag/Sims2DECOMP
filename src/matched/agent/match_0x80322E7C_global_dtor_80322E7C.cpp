/* global dtor at 0x80322E7C (44 bytes) */

void Init_dtor_80322E7C(int flag, unsigned int mask);

void global_dtor_80322E7C(void)
{
    Init_dtor_80322E7C(0, 0xFFFF);
}
