#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachWhenValueIsBelowLowerLimit) {
    EXPECT_EQ(inferBreach(-5.0, 0, 35), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite, InfersBreachWhenValueIsAboveUpperLimit) {
    EXPECT_EQ(inferBreach(50.0, 0, 35), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, InfersNormalWhenValueIsWithinLimits) {
    EXPECT_EQ(inferBreach(20.0, 0, 35), NORMAL);
}

TEST(TypeWiseAlertTestSuite, InfersLowerBoundaryAsNormal) {
    EXPECT_EQ(inferBreach(0.0, 0, 35), NORMAL);
}

TEST(TypeWiseAlertTestSuite, InfersUpperBoundaryAsNormal) {
    EXPECT_EQ(inferBreach(35.0, 0, 35), NORMAL);
}

