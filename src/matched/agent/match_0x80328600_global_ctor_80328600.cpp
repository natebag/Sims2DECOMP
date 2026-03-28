/* global ctor at 0x80328600 (44 bytes) */

void Init_ctor_80328600(int flag, unsigned int mask);

void global_ctor_80328600(void)
{
    Init_ctor_80328600(1, 0xFFFF);
}
