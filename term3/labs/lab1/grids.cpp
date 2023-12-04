#include <cassert>
#include <algorithm>

using namespace std;

template<typename T, size_t dim>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;

    [[nodiscard]] size_type get_size(size_type i) const { return dims[i]; }

    [[nodiscard]] size_type dims_prod() const
    {
        size_type res = 1;
        for (size_type i = 0; i < dim; ++i)
            res *= this->dims[i];

        return res;
    }

    explicit Grid(const T &t) : data(new T[1]{t}), dims(1) {}


    Grid(Grid<T, dim> const &other) : data(new T[other.dims_prod()]), dims(other.dims)
    {
        for (size_type i: dims)
            dims[i] = other.dims[i];

        for (size_type i: other.dims_prod())
            data[i] = other.data[i];
    }

    Grid(Grid<T, dim> &&other) noexcept: dims(dim) { swap(*this, other); };

    Grid(size_type dims_prod, const size_type (dims_)[]) : data(new T[dims_prod]), dims(dims_prod)
    {
        for (size_type i = 0; i < dim; ++i)
            dims[i] = dims_[i];
    }

    template<typename... args>
    Grid(T const &t, size_type size, args... kwargs): data(new T[dims_prod()]{t}), dims(size)
    {
        read_dims(size, kwargs...);
    }

    ~Grid() { delete[] data; }

    T &get_data(size_type idx) { return data[idx]; }

    void read_dims() {}

    template<typename... args>
    void read_dims(size_type size, args... kwargs)
    {
        this->dims[dim - 1 - sizeof...(kwargs)] = size;
        read_dims(kwargs...);
    }

    template<typename... args>
    T &operator()(size_type idx, args... kwargs) const
    {
        Grid<T, dim> idxs = Grid<T, dim>(T(), idx, kwargs...);
        size_type p = 1, data_idx = 0;
        auto prod = dims_prod();
        for (size_type i = 0; i < dim; ++i)
        {
            p *= get_size(i);
            data_idx += prod / p * idxs.dims[i];
        }

        return data[data_idx];
    }

    Grid<T, dim> &operator=(Grid<T, dim> const &other)
    {
        auto tmp = Grid(other);
        swap(*this, tmp);
        return *this;
    };

    Grid<T, dim> &operator=(Grid<T, dim> &&other) noexcept
    {
        auto tmp = Grid(std::move(other));
        swap(*this, tmp);
        return *this;
    };

    Grid<T, dim - 1> operator[](size_type idx0) const
    {
        size_type new_dims[dim - 1];
        size_type prod = 1;
        for (size_type i = 0; i < dim - 1; ++i)
        {
            new_dims[i] = dims[i + 1];
            prod *= dims[i + 1];
        }

        Grid<T, dim - 1> cut = Grid<T, dim - 1>(prod, new_dims);

        for (size_type i = 0; i < cut.dims_prod(); ++i)
        {
            auto shift = (dims_prod() / dims[0]) * idx0;
            cut.get_data(i) = data[shift + i];
        }
        return cut;
    }

private:
    T *data;
    size_type dims[dim];

    void swap(Grid<T, dim> &lha, Grid<T, dim> &rha)
    {
        std::swap(lha.dims, rha.dims);
        std::swap(rha.data, lha.data);
    }
};

int main()
{
    Grid<float, 3> const g3(1.0f, 2, 3, 4);
    assert(1.0f == g3(1, 1, 1));

    Grid<float, 2> g2(2.0f, 2, 5);
    assert(2.0f == g2(1, 1));

    g2 = g3[1];
    assert(1.0f == g2(1, 1));

    return 0;
}