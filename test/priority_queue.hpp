//
// Created by Tomáš Petříček on 24.08.2023.
//

#ifndef HEAP_TEST_PRIORITY_QUEUE_HPP
#define HEAP_TEST_PRIORITY_QUEUE_HPP

#include <boost/test/unit_test.hpp>
#include <priority_queue.hpp>
#include <algorithm>
#include <random>

BOOST_AUTO_TEST_SUITE(priority_queue_test)
    using value_type = int;

    BOOST_AUTO_TEST_CASE(default_constructor_test)
    {
        top::priority_queue<value_type> queue;
        BOOST_REQUIRE(queue.empty());
        BOOST_REQUIRE_EQUAL(queue.size(), 0);
    }

    BOOST_AUTO_TEST_CASE(push_test)
    {
        value_type max{-1}, size{0};
        top::priority_queue<value_type> queue;
        std::vector<value_type> data{1, 2, 0, 10, 5, 11};

        for (const value_type& val: data) {
            queue.push(val);
            BOOST_REQUIRE_EQUAL(++size, queue.size());
            max = std::max(max, val);
            BOOST_REQUIRE_EQUAL(queue.top(), max);
        }
    }

    BOOST_AUTO_TEST_CASE(pop_test)
    {
        auto comp = std::less<value_type>{};
        std::vector<value_type> data{{3, 10, 16, 22, 42, 4}};
        top::priority_queue<value_type> queue{comp, data};
        std::sort(data.begin(), data.end(), comp);

        while (!queue.empty()) {
            BOOST_REQUIRE_EQUAL(queue.empty(), data.empty());
            BOOST_REQUIRE_EQUAL(data.size(), queue.size());
            BOOST_REQUIRE_EQUAL(data.back(), queue.top());
            queue.pop();
            data.pop_back();
        }
        BOOST_REQUIRE_EQUAL(queue.empty(), data.empty());
        BOOST_REQUIRE_EQUAL(data.size(), queue.size());
    }

    std::vector<value_type> generate_data(std::size_t size, value_type min, value_type max)
    {
        std::uniform_int_distribution<value_type> dist{min, max};
        std::default_random_engine gen;
        std::vector<value_type> data(size);
        std::generate(data.begin(), data.end(), [&]() { return dist(gen); });
        return data;
    }

    BOOST_AUTO_TEST_CASE(make_heap_test)
    {
        auto comp = std::less<value_type>{};
        auto actual = generate_data(1'000, -100, 100);
        auto expect{actual};
        std::mt19937 gen(std::random_device{}());
        for (std::size_t i{0}; i<1'000; i++) {
            std::make_heap(expect.begin(), expect.end(), comp);
            top::make_heap(actual.begin(), actual.end(), comp);
//            BOOST_REQUIRE(expect==actual);
            std::shuffle(actual.begin(), actual.end(), gen);
            expect = actual;
        }
    }

    BOOST_AUTO_TEST_CASE(pop_heap_test)
    {
        auto comp = std::less<value_type>{};
        auto data = generate_data(1'000, -100, 100);
        auto expect{data}, actual{data};
        std::mt19937 gen(std::random_device{}());

        for (std::size_t i{0}; i<1'000; i++) {
            std::make_heap(actual.begin(), actual.end(), comp);
            std::make_heap(expect.begin(), expect.end(), comp);

            while(!actual.empty()) {
//                BOOST_REQUIRE_EQUAL(expect.front(), actual.front());
//                BOOST_REQUIRE_EQUAL(expect.size(), actual.size());
                std::pop_heap(expect.begin(), expect.end(), comp), expect.pop_back();
                top::pop_heap(actual.begin(), actual.end(), comp), actual.pop_back();
//                BOOST_REQUIRE(expect==actual);
            }
            std::shuffle(data.begin(), data.end(), gen);
            actual = expect = data;
        }
    }

    BOOST_AUTO_TEST_CASE(push_heap_test)
    {
        auto comp = std::less<value_type>{};
        auto data = generate_data(1'000, -100, 100);
        std::vector<int> expect, actual;
        std::mt19937 gen(std::random_device{}());

        for (std::size_t i{0}; i<1'000; i++) {
            for (const auto& val : data) {
                BOOST_REQUIRE_EQUAL(expect.size(), actual.size());
                expect.push_back(val), std::push_heap(expect.begin(), expect.end(), comp);
                actual.push_back(val), top::push_heap(actual.begin(), actual.end(), comp);
                BOOST_REQUIRE(std::is_heap(actual.begin(), actual.end(), comp));
                BOOST_REQUIRE(expect==actual);
            }
            actual.clear(), expect.clear();
            std::shuffle(data.begin(), data.end(), gen);
        }
    }
BOOST_AUTO_TEST_SUITE_END()

#endif //HEAP_TEST_PRIORITY_QUEUE_HPP
