/* global dtor at 0x8032B748 (44 bytes) */

void Init_dtor_8032B748(int flag, unsigned int mask);

void global_dtor_8032B748(void)
{
    Init_dtor_8032B748(0, 0xFFFF);
}
