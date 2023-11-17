#include <mettle/header_only.hpp>
#include "inter.hpp"

void test_impl(const std::vector<std::string>& lexems, const std::string& out_expr) {
    auto expr = getExpression(lexems);
    mettle::expect(expr, mettle::equal_to(out_expr));
}

mettle::suite<> basic("All Tests", [](auto& _) {

    _.test("Test 1", []() {
        test_impl({ "+", "-", "13", "4", "55" }, "((13 - 4) + 55)");
        });

    _.test("Test 2", []() {
        test_impl({ "+", "2", "*", "2", "-", "2", "1" }, "(2 + (2 * (2 - 1)))");
        });

    _.test("Test 3", []() {
        test_impl({ "+", "+", "10", "20", "30" }, "((10 + 20) + 30)");
        });

    _.test("Test 4", []() {
        test_impl({ "-", "-", "1", "2" }, "-(1 - 2)");
        });

    _.test("Test 5", []() {
        test_impl({ "/", "+", "3", "10", "*","+","2","3","-","3","5" }, "((3 + 10) / ((2 + 3) * (3 - 5)))");
        });
});
