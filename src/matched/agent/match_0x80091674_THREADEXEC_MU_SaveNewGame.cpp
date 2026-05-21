// 0x80091674 THREADEXEC_MU_SaveNewGame() (64B)

extern char gMemCardWrap_804858D8[16];
extern int g_save_flag_SDA;
extern "C" void THREADPOLL_MU_End();

class SimsMemCardWrap {
public:
    int SaveNewGame();
};

extern "C" void THREADEXEC_MU_SaveNewGame() {
    g_save_flag_SDA = 0;
    int ret = ((SimsMemCardWrap*)(*(void**)gMemCardWrap_804858D8))->SaveNewGame();
    if (ret == 1) {
        g_save_flag_SDA = ret;
    }
    THREADPOLL_MU_End();
}
