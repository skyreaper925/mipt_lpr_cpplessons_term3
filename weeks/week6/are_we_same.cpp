template<typename T, typename U, typename... args>
struct is_homogeneous
{
    static const bool value = false;
};

template<typename T, typename U>
struct is_homogeneous<T, U>
{
    static const bool value = false;
};


template<typename T>
struct is_homogeneous<T, T>
{
    static const bool value = true;
};


template<typename T, typename... args>
struct is_homogeneous<T, T, args...>
{
    static const bool value = is_homogeneous<T, args...>::value;
};


