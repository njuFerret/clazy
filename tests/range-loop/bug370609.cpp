// bug 370609, Simply tests if clazy crashes

#include <QtCore/QVector>

template <typename T>
struct Example
{
    Example()
    {
        for (auto sample : m_sampleCache) { }
    }
    QVector<int> m_sampleCache;
};

void CreateExample()
{
    new Example<int>();
}
