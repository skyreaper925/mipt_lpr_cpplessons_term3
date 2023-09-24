cmake_minimum_required(VERSION 3.25)
project(mipt_lpr_cpplessons_term3)

set(CMAKE_CXX_STANDARD 23)

add_executable(clouds weeks/week1/clouds.cpp)

add_executable(Tsort weeks/week2/Tsort.cpp)
add_executable(min_max_greater_less weeks/week2/min_max_greater_less.cpp)
add_executable(Tread weeks/week2/Tread.cpp)
add_executable(Tprint weeks/week2/Tprint.cpp)
add_executable(Tsum_array weeks/week2/Tsum_array.cpp)

add_executable(31 weeks/week3/1.cpp)
add_executable(ExplcitInt weeks/week3/ExplcitInt.cpp)
add_executable(fractions weeks/week3/fractions.cpp)
add_executable(point weeks/week3/contest.cpp)

add_executable(41 weeks/week4/1.cpp)
add_executable(contest weeks/week4/branch_heir.cpp)
add_executable(characters weeks/week4/characters.cpp)
add_executable(branch_heir weeks/week4/branch_heir.cpp)
add_executable(expression weeks/week4/expression.cpp)
add_executable(dice_with_rice weeks/week4/dice_with_rice.cpp)