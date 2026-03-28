struct EStream_ISS {
    int m_isStreaming;
    int IsStreamingStructure();
};

int EStream_ISS::IsStreamingStructure() {
    return m_isStreaming;
}
