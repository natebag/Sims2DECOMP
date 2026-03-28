// Test: Match ESimsApp::GetDefaultLanguage
// Target: 0x800044C0 (8 bytes)
// Expected PPC: li r3, 0; blr
// Expected bytes: 38 60 00 00 4E 80 00 20

class ESimsApp {
public:
    int GetDefaultLanguage();
};

int ESimsApp::GetDefaultLanguage() {
    return 0;
}
