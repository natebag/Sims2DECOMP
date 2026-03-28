/* global dtor at 0x80324D34 (44 bytes) */

void Init_dtor_80324D34(int flag, unsigned int mask);

void global_dtor_80324D34(void)
{
    Init_dtor_80324D34(0, 0xFFFF);
}
