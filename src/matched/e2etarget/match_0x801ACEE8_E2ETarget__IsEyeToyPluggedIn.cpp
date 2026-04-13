// 0x801ACEE8 E2ETarget::IsEyeToyPluggedIn (36B)
extern int EyeToyClient_IsSessionEyeToyDisconnected();

struct E2ETarget_IETPI {
    int IsEyeToyPluggedIn();
};

int E2ETarget_IETPI::IsEyeToyPluggedIn() {
    return EyeToyClient_IsSessionEyeToyDisconnected() ^ 1;
}
