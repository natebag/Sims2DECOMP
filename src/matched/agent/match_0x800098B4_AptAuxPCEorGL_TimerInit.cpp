/* AptAuxPCEorGL_TimerInit(void) at 0x800098B4 (36B) */

extern int* g_timerObj;

void TimerInit(int*);

void AptAuxPCEorGL_TimerInit(void) {
    TimerInit(g_timerObj);
}
