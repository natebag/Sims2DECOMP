/* fseek wrapper at 0x803C71AC (68 bytes) */

int CheckAvail3(void* ctx);
void DoSeek3(void* ctx);

int fseek_wrapper3(void* ctx)
{
    int result = CheckAvail3(ctx);
    if (result == 0) {
        return 0;
    }
    DoSeek3(ctx);
    return 1;
}
