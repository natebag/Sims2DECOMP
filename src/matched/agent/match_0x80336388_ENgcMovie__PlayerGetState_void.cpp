// FLAGS: -fno-schedule-insns
// 0x80336388 ENgcMovie::PlayerGetState(void) (12B)
// lis r9,gState@ha; lbz r3,gState@l(r9); blr  -- absolute (non-SDA) byte global
// large array forces non-SDA absolute lis/lbz addressing
extern unsigned char gMoviePlayerState[16];

struct ENgcMovie {
    int PlayerGetState();
};

int ENgcMovie::PlayerGetState() {
    return gMoviePlayerState[0];
}
