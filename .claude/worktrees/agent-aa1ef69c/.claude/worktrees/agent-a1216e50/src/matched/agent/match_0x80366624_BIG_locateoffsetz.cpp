typedef unsigned int u32;

extern "C" {

int BIG_locateoffsetz_internal(void* bigfile, char* name, int index, u32* offset, int flags);

u32 BIG_locateoffsetz(void* bigfile, char* name)
{
    u32 offset = 0;
    if (name != 0) {
        BIG_locateoffsetz_internal(bigfile, name, 0, &offset, 0);
    }
    return offset;
}

}
