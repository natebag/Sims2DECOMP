extern int gWaitDoneFlag;
extern int gWaitOnName;

void SleepFunc(int frames);

void AptAuxPCEorGL_WaitOn(char* name) {
    gWaitOnName = (int)name;
    gWaitDoneFlag = 0;
    do {
        SleepFunc(1);
    } while (gWaitDoneFlag == 0);
    gWaitOnName = 0;
}
