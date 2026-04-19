/* cTrack::SetPan(int) at 0x80118c4c (40B) */

struct cTrack_SetPan {
    void SetRegister(int reg, int val);
    void SetPan(int val);
};

void cTrack_SetPan::SetPan(int val) {
    SetRegister(10, val);
}
