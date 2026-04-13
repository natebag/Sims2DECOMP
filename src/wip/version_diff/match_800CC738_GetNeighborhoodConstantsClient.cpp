/* GetNeighborhoodConstantsClient(void) - 8 bytes */

struct NeighborhoodConstants {
    int m_data;
};

static NeighborhoodConstants s_neighborhoodConstants;

NeighborhoodConstants *GetNeighborhoodConstantsClient(void) {
    return &s_neighborhoodConstants;
}
