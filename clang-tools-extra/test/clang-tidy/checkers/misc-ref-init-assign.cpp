// RUN: %check_clang_tidy %s misc-ref-init-assign %t

float Num1 = 0;
float &RefOne = Num1;

void test()
{
    RefOne = 3;
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: reference type variable 'RefOne' is assigned after initialization [misc-ref-init-assign]
}

void valid()
{
    int A;
    int &RefA = A;

    A = 3;
}
