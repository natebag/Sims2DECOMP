// 0x8007578C SimsMemCardWrap::PreloadGame(int) (144 B)

struct StringBuffer2 { char* c_str() const; };
struct Globals { char pad[0x148]; char* ptr; };
struct MUSlotStatus_t { int pad0; int index; int pad8; int padC; char* a[2]; char* b[2]; };
extern Globals _globals;
extern MUSlotStatus_t MUSlotStatus;
extern void* g_nghFileDesc;
extern int NghResFile__ReadChecksumFromCard_char_ptr__int(void*, int);
extern void CheckForFileDescriptorLeaks_char_ptr__int(void*, int);

int SimsMemCardWrap_PreloadGame(int slot) {
    MUSlotStatus.a[MUSlotStatus.index] = ((StringBuffer2*)(_globals.ptr + 0xA0))->c_str();
    MUSlotStatus.b[MUSlotStatus.index] = ((StringBuffer2*)(_globals.ptr + 0x58))->c_str();
    int ret = NghResFile__ReadChecksumFromCard_char_ptr__int(g_nghFileDesc, slot);
    CheckForFileDescriptorLeaks_char_ptr__int(g_nghFileDesc, slot);
    return ret;
}
