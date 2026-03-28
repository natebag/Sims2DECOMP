/* EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int) - 0x800387B4 (8 bytes) */

extern void *g_macroBlockDummyBuffer;

struct EyeToyClient {
    static void* MacroBlockDummyAllocator(unsigned int, unsigned int);
};

void* EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int) {
    return g_macroBlockDummyBuffer;
}
