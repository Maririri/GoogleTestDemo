//
// Created by Maria.Baburina on 6/30/2017.
//

#include "../samples/prime_tables.h"
#include "gtest/gtest.h"

//#if GTEST_HAS_PARAM_TEST

using ::testing::TestWithParam;
using ::testing::Values;

// As a general rule, to prevent a test from affecting the tests that come
// after it, you should create and destroy the tested objects for each test
// instead of reusing them.  In this sample we will define a simple factory
// function for PrimeTable objects.  We will instantiate objects in test's
// SetUp() method and delete them in TearDown() method.
typedef PrimeTable *CreatePrimeTableFunc();

PrimeTable *CreateOnTheFlyPrimeTable() { return new OnTheFlyPrimeTable(); }

template <size_t max_precalculated>
PrimeTable *CreatePreCalculatedPrimeTable() {
  return new PreCalculatedPrimeTable(max_precalculated);
}

// Inside the test body, fixture constructor, SetUp(), and TearDown() you
// can refer to the test parameter by GetParam().  In this case, the test
// parameter is a factory function which we call in fixture's SetUp() to
// create and store an instance of PrimeTable.
class PrimeTableTest2 : public TestWithParam<CreatePrimeTableFunc *> {
public:
  virtual ~PrimeTableTest2() { delete table_; }
  virtual void SetUp() { table_ = (*GetParam())(); }
  virtual void TearDown() {
    delete table_;
    table_ = NULL;
  }

protected:
  PrimeTable *table_;
};

TEST_P(PrimeTableTest2, ReturnsFalseForNonPrimes2) {
  ASSERT_FALSE(table_->IsPrime(-5));
  EXPECT_FALSE(table_->IsPrime(-5));
  EXPECT_FALSE(table_->IsPrime(0));
  EXPECT_FALSE(table_->IsPrime(1));
  EXPECT_FALSE(table_->IsPrime(4));
  EXPECT_FALSE(table_->IsPrime(6));
  EXPECT_FALSE(table_->IsPrime(100));
}

TEST_P(PrimeTableTest2, ReturnsTrueForPrimes2) {
  EXPECT_TRUE(table_->IsPrime(2));
  EXPECT_TRUE(table_->IsPrime(3));
  EXPECT_TRUE(table_->IsPrime(5));
  EXPECT_TRUE(table_->IsPrime(7));
  EXPECT_TRUE(table_->IsPrime(11));
  EXPECT_TRUE(table_->IsPrime(131));
}

TEST_P(PrimeTableTest2, CanGetNextPrime2) {
  EXPECT_EQ(2, table_->GetNextPrime(0));
  EXPECT_EQ(3, table_->GetNextPrime(2));
  EXPECT_EQ(5, table_->GetNextPrime(3));
  EXPECT_EQ(7, table_->GetNextPrime(5));
  EXPECT_EQ(11, table_->GetNextPrime(7));
  EXPECT_EQ(131, table_->GetNextPrime(128));

  EXPECT_TRUE(1 == 3.14);
}

// In order to run value-parameterized tests, you need to instantiate them,
// or bind them to a list of values which will be used as test parameters.
// You can instantiate them in a different translation module, or even
// instantiate them several times.
//
// Here, we instantiate our tests with a list of two PrimeTable object
// factory functions:
INSTANTIATE_TEST_CASE_P(OnTheFlyAndPreCalculated, PrimeTableTest2,
                        Values(&CreateOnTheFlyPrimeTable,
                               &CreatePreCalculatedPrimeTable<1000>));
