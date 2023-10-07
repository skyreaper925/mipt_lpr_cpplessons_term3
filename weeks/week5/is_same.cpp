template<typename T, typename U>
struct same
{
    static constexpr bool value = false;
};

template<typename T>
struct same<T, T>
{
    static constexpr bool value = true;
};

template<typename T, typename U>
bool is_same(T lha, U rha)
{
    return same<T, U>::value;
}
