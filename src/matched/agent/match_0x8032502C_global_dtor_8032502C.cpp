/* global dtor at 0x8032502C (44 bytes) */

void Init_dtor_8032502C(int flag, unsigned int mask);

void global_dtor_8032502C(void)
{
    Init_dtor_8032502C(0, 0xFFFF);
}
