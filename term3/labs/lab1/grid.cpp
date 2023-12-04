#include <iostream>

using namespace std;

template<typename T>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;

    [[nodiscard]] size_type get_y_size() const { return y_size; }

    [[nodiscard]] size_type get_x_size() const { return x_size; }

    T &operator[](size_type y_idx, size_type x_idx) { return data[y_idx * x_size + x_idx]; }

    explicit Grid(const T &t) : data(t), y_size(1), x_size(1)
    {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it)
            *it = t;
    }

    Grid<T> &operator=(Grid<T> &) = delete;

    Grid<T> &operator=(Grid<T> &&) = delete;

    Grid(Grid<T> const &) = delete;

    Grid(Grid<T> &&) = delete;

    Grid(size_type y_size, size_type x_size, const T &t) : data(new T[y_size * x_size]{t}), y_size(y_size), x_size
            (x_size)
    {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it)
            *it = t;
    }

//    T operator()(size_type y_idx, size_type x_idx) const
//    {
//        cout << "const ()" << endl;
//        return data[y_idx * x_size + x_idx];
//    }

    T &operator()(size_type y_idx, size_type x_idx)
    {
        cout << "no const ()" << endl;
        return data[y_idx * x_size + x_idx];
    }

    class Proxy
    {
    public:
        Proxy(T *row, size_type x_size) : row(row), x_size(x_size) {}

        T &operator[](size_type x_idx)
        {
            return row[x_idx];
        }

        const T &operator[](size_type x_idx) const
        {
            return row[x_idx];
        }

    private:
        T *row;
        size_type x_size;
    };

    Proxy operator[](size_type y_idx)
    {
        cout << "no const []" << endl;
        return Proxy(data + y_idx * x_size, x_size);
    }

//    Proxy operator[](size_type y_idx) const
//    {
//        return Proxy(data + y_idx * x_size, x_size);
//    }

    Grid<T> &operator=(T const &t)
    {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it)
            *it = t;
        cout << "= operator" << endl;
        return *this;
    }

private:
    T *data;
    size_type const y_size, x_size;
};

#include<cassert>

int main()
{
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<int>::size_type;
    Grid<float> g1(3, 2, 0.0f);
    cout << g1(1, 1) << endl;
    g1(1, 1) = 2;

    cout << g1[1][1] << endl;
    g1[1][1] = 2;

//    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
//        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
//            assert(0.0f == g[y_idx][x_idx]);
//
//    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
//        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
//            g[y_idx][x_idx] = 1.0f;
//
//    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
//        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
//            assert(1.0f == g(y_idx, x_idx));

//    Grid<float, 3> const g3(2, 3, 4, 1.0f);
//    assert(1.0f == g3(1, 1, 1));
//
//    Grid<float, 2> g2(2, 5, 2.0f);
//    assert(2.0f == g2(1, 1));
//
//    g2 = g3[1];
//    assert(1.0f == g2(1, 1));

    return 0;
}
