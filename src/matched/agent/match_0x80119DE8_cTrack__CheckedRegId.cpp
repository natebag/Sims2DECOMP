// 0x80119DE8 cTrack::CheckedRegId(int) (64B)
// Bounds-check id against max 18; call HandleTrackFlowError if out of range.
// mr r3,r4 scheduled before branch (default scheduling fills pipeline slot).

extern char g_RegIdError[];

struct cTrack_CRI {
    void HandleTrackFlowError(char* msg);
    int CheckedRegId(int id);
};

int cTrack_CRI::CheckedRegId(int id) {
    if (id <= 18) return id;
    HandleTrackFlowError(g_RegIdError);
    return 1;
}
