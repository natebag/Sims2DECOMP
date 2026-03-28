typedef unsigned int u32;

extern "C" {

u32 BIG_locateoffset(void* bigfile, char* name);

void* BIG_locate(void* bigfile, char* name)
{
    void* result = 0;
    u32 offset = BIG_locateoffset(bigfile, name);
    if (offset != 0) {
        result = (void*)((char*)bigfile + offset);
    }
    return result;
}

}
