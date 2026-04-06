// 0x800587EC MoviePlayerEndgameMovieState::Shutdown (52b)
extern char g_eapp_800587EC[];
extern char g_gdata_800587EC[];
void mp_isplaying_800587EC(char*);
void mp_setbg_800587EC(char*);

void MoviePlayerEndgameMovieState_Shutdown(void* self) {
    mp_isplaying_800587EC(g_eapp_800587EC);
    mp_setbg_800587EC(g_gdata_800587EC);
}
