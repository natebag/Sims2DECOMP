/* AptRenderingContext::getVertexMatrix(AptMatrix *) - 0x802AB380 (128B) */

struct Matrix6 {
    int w[6];  // 24 bytes
};

extern char g_aptDefaultMatrix[100];

class AptRenderingContext {
public:
    char pad0[32];
    Matrix6 m_current;       // +32
    char pad1[512];          // fill to +568
    Matrix6 m_stack[16];     // +568
    char pad2[4];            // +952 pad
    int m_depth;             // +956

    void getVertexMatrix(Matrix6* out);
};

void AptRenderingContext::getVertexMatrix(Matrix6* out) {
    if (m_depth > 0) {
        *out = m_current;
    } else {
        *out = *(Matrix6*)g_aptDefaultMatrix;
    }
}
