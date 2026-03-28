/* global ctor at 0x80325000 (44 bytes) */

void Init_ctor_80325000(int flag, unsigned int mask);

void global_ctor_80325000(void)
{
    Init_ctor_80325000(1, 0xFFFF);
}
