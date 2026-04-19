// 0x800073E0 (60B) setVertexMatrix(AptMatrix*)
// Copy 6 floats from AptMatrix to global vertexMatrix at rows [0,1,3].

struct AptMatrix {
    float m00, m01, m10, m11, m20, m21;  // 2x3
};

extern "C" float vertexMatrix[16];

void setVertexMatrix(AptMatrix* m) {
    vertexMatrix[0]  = m->m00;
    vertexMatrix[1]  = m->m01;
    vertexMatrix[4]  = m->m10;
    vertexMatrix[5]  = m->m11;
    vertexMatrix[12] = m->m20;
    vertexMatrix[13] = m->m21;
}
