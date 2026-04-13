/* GetMotiveConstantsClient(void) - 8 bytes */

struct MotiveConstants {
    int m_data;
};

static MotiveConstants s_motiveConstants;

MotiveConstants *GetMotiveConstantsClient(void) {
    return &s_motiveConstants;
}
