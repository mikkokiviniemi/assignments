#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "math.h"

TEST_CASE("testing math functions") {
    CHECK(add(3,3)==6);
    CHECK(substract(3,3) == 0);
    CHECK_THROWS_AS(divide(3,0), std::logic_error);
    CHECK(multiple(3,3) == 9);
    CHECK(divide(6,3)==2);
}


TEST_CASE("testing string functions") {
    CHECK(reverse_string("Saatana") == "anataaS");
    CHECK(upper_case_string("Saatana") == "SAATANA");
    CHECK(lower_case_string("Saatana") == "saatana");
    CHECK(is_palindrome("Saatana") == false);
    CHECK(is_palindrome("saippuakauppias") == true);
}


TEST_CASE("testing banking functions") {
    Bank_account new_account = {"Testi","Testikuja1","1800-testi","testi",0.0f};
    new_account.deposit_money(2.0f);
    CHECK(new_account.balance == 2.0);
    new_account.withdraw_money(2.0);
    CHECK(new_account.balance == 0.0);
    
}