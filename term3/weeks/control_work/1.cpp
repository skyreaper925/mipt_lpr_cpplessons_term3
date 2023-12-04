//
// Created by user on 02.12.2023.
//

enum class CellState
{
    A, B
};

struct Cell
{
    virtual void flip() = 0;

    [[nodiscard]] virtual CellState current() const = 0;

    virtual ~Cell() = default;
};

void bulk_flip(Cell **begin_cells, Cell **end_cells)
{
    for (auto it = begin_cells; it != end_cells; ++begin_cells)
        (*it)->flip();
}

class ABLoopCell : public Cell
{
public:

    CellState state;

    explicit ABLoopCell(CellState initial_state) : state(initial_state) {};

    void flip() override { this->state = (CellState::A == current() ? CellState::B : CellState::A); }

//    [[nodiscard]]
    CellState current() const override { return this->state; }
};

class ABDeadCell : public Cell
{
public:

    CellState state;

    explicit ABDeadCell(CellState initial_state) : state(initial_state) {};

    void flip() override { this->state = CellState::B; }

//    [[nodiscard]]
    CellState current() const override { return this->state; }
};

class BADeadCell : public Cell
{
public:
    CellState state;

    explicit BADeadCell(CellState initial_state) : state(initial_state) {};

    void flip() override { this->state = CellState::B; }

//    [[nodiscard]]
    CellState current() const override { return this->state; }
};