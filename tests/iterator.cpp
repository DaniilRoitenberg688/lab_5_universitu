#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>


bool equal_two_double_vectors(const std::vector<double>& result, const std::vector<double>& expected, double eps = 1e-9) {
    if (result.size() != expected.size()) {
        std::cout << "size of result: " << result.size() << "\n" << "doesn't equal to size of expected: " << expected.size() << "\n";
        return false;
    }

    auto res_it = result.begin();
    auto ex_it = expected.begin();

    while (res_it != result.end()) {
        if (std::abs(*res_it - *ex_it) > eps) {
            std::cout << "the element of result: " << *res_it << "\n" << "doesn't equal to the element of expected: " << *ex_it << "\n" << "at index: " << std::distance(result.begin(), res_it) << "\n";
            return false;
        }
        res_it++; ex_it++;
    }
    return true;
}


std::vector<double> return_numbers_on_even_positions_10(const std::vector<double>& numbers) {
    std::vector<double> result;
    int index = 0;
    auto condition = [&index](const double& val) {
        return index++ % 2 == 0;
    };
    std::remove_copy_if(numbers.begin(), numbers.end(), std::back_inserter(result), condition);
    return result;
}

TEST(Test10, TestWithTreeNumbers) {
    std::vector<double> v = {1.0, 2.0, 3.0};
    auto res = return_numbers_on_even_positions_10(v);
    std::vector<double> ex = {2.0};
    bool comp = equal_two_double_vectors(res, ex);
    EXPECT_TRUE(comp);
}


TEST(Test10, TestWithSixNumbers) {
    std::vector<double> v = {1.0, 2.0, 3.0, 5.0, 7.0};
    auto res = return_numbers_on_even_positions_10(v);
    std::vector<double> ex = {2.0, 5.0};
    bool comp = equal_two_double_vectors(res, ex);
    EXPECT_TRUE(comp);
}

TEST(Test10, TestWithOneElement) {
    std::vector<double> v = {1.0};
    auto res = return_numbers_on_even_positions_10(v);
    std::vector<double> ex = {};
    bool comp = equal_two_double_vectors(res, ex);
    EXPECT_TRUE(comp);
}


std::vector<int> get_numbers_from_file_and_leave_only_at_uneven_positions_9(const std::string& name) {
    std::vector<int> res;
    std::ifstream file(name);
    std::istream_iterator<int> file_it(file);
    std::istream_iterator<int> end_it;

    int index = 0;

    std::remove_copy_if(file_it, end_it, std::back_inserter(res), [&index](int v) {
        return index++ % 2 != 0;
    });
    return res;

}

TEST(Test9, TestThreeElements) {
    auto name = "files/9/three.txt";
    std::vector<int> expected {1, 3};
    auto res = get_numbers_from_file_and_leave_only_at_uneven_positions_9(name);
    EXPECT_EQ(expected, res);
}


TEST(Test9, TestSixElements) {
    auto name = "files/9/six.txt";
    std::vector<int> expected {1, 3, 5};
    auto res = get_numbers_from_file_and_leave_only_at_uneven_positions_9(name);
    EXPECT_EQ(expected, res);
}

TEST(Test9, TestOneElements) {
    auto name = "files/9/one.txt";
    std::vector<int> expected {1};
    auto res = get_numbers_from_file_and_leave_only_at_uneven_positions_9(name);
    EXPECT_EQ(expected, res);
}


void write_star_to_file_n_times_18(std::string name, int n) {
    std::ofstream file(name);
    std::ostream_iterator<std::string> it(file, " ");
    std::fill_n(it, n, "*");
}


bool check_file_content(std::string name, std::string expected) {
    std::ifstream file(name);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    return content == expected;
}

TEST(Test18, TestFive) {
    std::string name = "files/18/five.txt";
    write_star_to_file_n_times_18(name, 5);
    EXPECT_TRUE(check_file_content(name, "* * * * * "));
}

TEST(Test18, Test10) {
    std::string name = "files/18/ten.txt";
    write_star_to_file_n_times_18(name, 10);
    EXPECT_TRUE(check_file_content(name, "* * * * * * * * * * "));
}
