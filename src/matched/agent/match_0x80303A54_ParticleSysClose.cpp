extern char gPSys1[4];
extern char gPSys2[4];
extern char gPSys3[4];
extern "C" void closeSys(char*);
int ParticleSysClose() {
    closeSys(gPSys1);
    closeSys(gPSys2);
    closeSys(gPSys3);
    return 0;
}
