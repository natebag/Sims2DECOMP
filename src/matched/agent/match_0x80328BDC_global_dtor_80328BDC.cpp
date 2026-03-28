/* global dtor at 0x80328BDC (44 bytes) */

void Init_dtor_80328BDC(int flag, unsigned int mask);

void global_dtor_80328BDC(void)
{
    Init_dtor_80328BDC(0, 0xFFFF);
}
