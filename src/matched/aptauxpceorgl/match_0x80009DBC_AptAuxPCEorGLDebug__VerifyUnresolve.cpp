/* AptAuxPCEorGLDebug_VerifyUnresolve(bool) at 0x80009DBC (8B) */

extern int g_verifyUnresolve;

void AptAuxPCEorGLDebug_VerifyUnresolve(int val) {
    g_verifyUnresolve = val;
}
