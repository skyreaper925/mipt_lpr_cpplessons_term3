#include <iostream>
#include <vector>

using namespace std;

class MyArray
{
public:
    explicit MyArray(size_t size) : m_size(size), m_buffer(new int[m_size]) {}

    ~MyArray() { delete[] m_buffer; }

    //обязательно для итерирования
    class MyIterator
    {
    public:
        using iterator_category = forward_iterator_tag;

        //using iterator_category = bidirectional_iterator_tag; нужно описать еще operator--
        // у вектора using iterator_category = random_access_iterator_tag; нужно еще дописать operator[]
        // using iterator_category = random_access_iterator_tag;
        explicit MyIterator(int *ptr) : m_ptr(ptr) {}

        MyIterator operator++()
        {
            ++m_ptr;
            return *this;
        }

        friend bool operator!=(const MyIterator &lha, const MyIterator &rha)
        {
            return (lha.m_ptr != rha.m_ptr);
        }

        int &operator*() const { return *m_ptr; };
        //int* operator->() { return m_ptr; };


    private:
        int *m_ptr;
    };


    //обязательно для итерирования
    MyIterator begin() { return MyIterator(&(m_buffer[0])); }

    MyIterator end() { return MyIterator(&(m_buffer[m_size])); } //элемент за последним (по хорошему надо
    // реализовывать NILL элемент)


private:
    size_t m_size = 0;
    int *m_buffer = nullptr;
};

// Должен быть итератор, чтобы писать такие for циклы как со стандартными контейнерами

int main()
{
    int y = 12;
    int *x = &y;
    vector<int> cont2 = {1, 2, 3, 4, 5};
    MyArray cont = MyArray(12);
    auto it = MyArray::MyIterator(nullptr);
    vector<int> vect = {1, 2, 3};
    next(vect.begin());
    prev(vect.end());
    vect.cbegin(); //const iterator
    vect.rbegin(); //reverse begin

    /*
    
    vect.begin() -> vect.end()
    vect.rbegin() -> vect.rend()

    */

    for (auto el: cont)
    {
        cout << el << " ";
    }
    /*for (auto el: cont2)
    {
        cout << type(el).name() << " ";
    }*/
    cout << endl;
    return 0;
}