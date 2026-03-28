/* global dtor at 0x8032F300 (44 bytes) */

void Init_dtor_8032F300(int flag, unsigned int mask);

void global_dtor_8032F300(void)
{
    Init_dtor_8032F300(0, 0xFFFF);
}
