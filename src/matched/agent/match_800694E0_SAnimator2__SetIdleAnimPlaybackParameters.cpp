typedef unsigned char u8;

struct EACTrack {
    u8 _pad0[0x0D];
    char m_loopFlag;
};

void EAnimController_SetTrackSpeed(void*, EACTrack*, float);

void SAnimator2_SetIdleAnimPlaybackParameters(u8* pThis, EACTrack* pTrack) {
    if (pTrack != 0) {
        void* pData = *(void**)(pThis + 0x08);
        float speed = *(float*)(pThis + 0xFC);
        EAnimController_SetTrackSpeed((u8*)pData + 0x334, pTrack, speed);
        pTrack->m_loopFlag = 0;
    }
}
