// 0x802CA644 EMat4::GetMaxScale() const (88B)
// L1-norm column max of upper-left 3x3: max over col of sum |m[row][col]| for row 0..2.
// Outer for col, inner ctr-loop for row, fabs accumulator, NaN-loose `!(>)` selector via ble.

extern "C" float fabsf(float);

class EMat4 {
public:
    float m[4][4];
    float GetMaxScale() const;
};

float EMat4::GetMaxScale() const {
    float maxNorm = 0.0f;
    for (int col = 0; col < 3; col++) {
        float sum = 0.0f;
        for (int row = 0; row < 3; row++) {
            sum += fabsf(m[row][col]);
        }
        if (sum > maxNorm) maxNorm = sum;
    }
    return maxNorm;
}
