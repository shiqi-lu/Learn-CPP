template <typename T>
inline T const & max(T const & a, T const & b)
{
    return a < b ? b : a;
}
