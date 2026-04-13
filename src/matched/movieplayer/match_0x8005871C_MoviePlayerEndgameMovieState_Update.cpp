// 0x8005871C MoviePlayerEndgameMovieState::Update (92b)
extern char g_eapp[];
extern void* g_sda_ptr;

int mp_somecheck(char*);
int mp_isplaying(char*);
void mp_somefunc(void*);
void mp_gotogame(void*);

void Update_test(void* self, float dt) {
    if (mp_somecheck(g_eapp) == 0) {
        if (mp_isplaying(g_eapp) == 0) {
            mp_somefunc(g_sda_ptr);
            mp_gotogame(self);
        }
    }
}
