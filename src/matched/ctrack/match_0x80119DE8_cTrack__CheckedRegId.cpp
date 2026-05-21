// 0x80119DE8 (64B) cTrack::CheckedRegId(int)

extern char str_cTrackRegIdError[];  // 0x803DC45C

class cTrack {
public:
    void HandleTrackFlowError(char* msg);
    int CheckedRegId(int regId);
};

int cTrack::CheckedRegId(int regId) {
    if (regId <= 18) return regId;
    HandleTrackFlowError(str_cTrackRegIdError);
    return 1;
}
