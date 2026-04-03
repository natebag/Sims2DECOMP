// 0x801A8D78 (84 bytes)
// _MotiveSort(void *, void *)
// Comparison function for sorting motives by priority

struct MotivePriority {
    int m_motivId;
    // float m_priority is stored in global array indexed by id
};

// Global motive priority array at SDA offset -31824(r13)
extern float *g_motivePriority;

int _MotiveSort(void *a, void *b) {
    const MotivePriority *ma = (const MotivePriority *)a;
    const MotivePriority *mb = (const MotivePriority *)b;
    
    // Get priority values for each motive
    float priorityA = g_motivePriority[ma->m_motivId];
    float priorityB = g_motivePriority[mb->m_motivId];
    
    // Compare (subtract to get sort order)
    float diff = priorityA - priorityB;
    
    // Return sign of difference
    if (diff > 0.0f) {
        return 1;
    } else if (diff < 0.0f) {
        return -1;
    }
    return 0;
}
