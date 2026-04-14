/* ESimsApp::ESimsApp(void) at 0x80004340 (88B) */

extern int ESimsApp_vtable[];

struct EApp {
    EApp();
};

struct ESimsApp : public EApp {
    char pad_app[0x338 - sizeof(EApp)];
    int* m_vtable338;
    char pad_33c[0x478 - 0x33C];
    int m_field478;
    char pad_47c[0x04];
    int m_field480;
    char m_field484;
    char pad_485[0x03];
    int m_field488;
    int m_field48C;
    int m_field490;

    ESimsApp();
};

ESimsApp::ESimsApp() : EApp() {
    m_field478 = 0;
    m_field480 = 0;
    m_field484 = 0;
    m_field488 = 0;
    m_field48C = 0;
    m_vtable338 = ESimsApp_vtable;
    m_field490 = 0;
}
