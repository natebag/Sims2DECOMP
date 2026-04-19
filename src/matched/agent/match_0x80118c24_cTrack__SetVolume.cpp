/* cTrack::SetVolume(int) at 0x80118c24 (40B) */

struct cTrack_SetVolume {
    void SetRegister(int reg, int val);
    void SetVolume(int val);
};

void cTrack_SetVolume::SetVolume(int val) {
    SetRegister(9, val);
}
