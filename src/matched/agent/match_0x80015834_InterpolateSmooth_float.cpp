// 0x80015834 {anonymous}::InterpolateSmooth<float>(float*, float&, float, float) (76B)
// Smooth-step interpolator with epsilon snap and step clamp.
// NaN-loose `!(>)` early-snap (ble) + NaN-loose ble-inverse-skip clamp.
// Anonymous namespace, fabsf via PPC fabs single-insn.

extern "C" float fabsf(float);

namespace {

void InterpolateSmooth(float* out, float& target, float speed1, float speed2) {
    float diff = target - *out;
    if (fabsf(diff) > 0.0001f) {
        float step = diff * speed1 * speed2;
        if (fabsf(step) > fabsf(diff)) {
            step = diff;
        }
        *out = *out + step;
    } else {
        *out = target;
    }
}

}
