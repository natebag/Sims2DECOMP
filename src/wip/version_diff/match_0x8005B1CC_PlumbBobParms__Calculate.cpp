/* PlumbBobParms::Calculate(void) at 0x8005B1CC (24B) */

extern float g_plumbBobConstants[4];

struct PlumbBobParms {
    char pad_0[0x28];
    float m_field_28;
    char pad_2C[0x30];
    float m_field_5C;

    void Calculate(void);
};

void PlumbBobParms::Calculate(void) {
    m_field_5C = g_plumbBobConstants[0] / m_field_28;
}
