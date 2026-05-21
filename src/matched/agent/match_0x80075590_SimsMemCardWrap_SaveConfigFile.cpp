// 0x80075590 SimsMemCardWrap::SaveConfigFile (76b)
// ASMPROC_swap_adj: a=lis, b=mr, which=first

struct OptionsReconGlobal {
    int* ptr;
    int pad[2];
};
extern OptionsReconGlobal g_pOptionsRecon;
extern int OptionsRecon__WriteOut_void(int*);
extern int InvalidatePS2SavedGame_int(int);

int SimsMemCardWrap_SaveConfigFile(int slot) {
    int result = OptionsRecon__WriteOut_void(g_pOptionsRecon.ptr);
    if (result != 1) {
        InvalidatePS2SavedGame_int(slot);
    }
    return result;
}
