// 0x80058778 MoviePlayerEndgameMovieState::GotoGame (112b)
// FLAGS: -fno-elide-constructors
// 0x80058778 MoviePlayerEndgameMovieState::GotoGame (112b)
extern char g_flag_gg[];
extern char g_gdata_gg[];
extern char g_floatA_gg[];
extern char g_floatB_gg[];

void gg_set_mode(int);
void gg_setup_bg(char*);
void gg_owner_set(void*, int, float);
void gg_load_ui(char*);
void gg_set_flow(void*);

void GotoGame_test(void* self) {
    *(int*)g_flag_gg = 0;
    gg_set_mode(4);
    gg_setup_bg(g_gdata_gg);
    gg_owner_set(self, 13, *(float*)g_floatA_gg);
    gg_load_ui(g_floatB_gg);
    gg_set_flow(*(void**)((char*)self + 8));
}
