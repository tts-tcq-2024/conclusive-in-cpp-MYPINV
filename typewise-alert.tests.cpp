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

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForPassiveCoolingLowTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -1.0), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForPassiveCoolingHighTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36.0), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForPassiveCoolingNormalTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20.0), NORMAL);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForHiActiveCoolingLowTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1.0), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForHiActiveCoolingHighTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46.0), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForHiActiveCoolingNormalTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40.0), NORMAL);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForMedActiveCoolingLowTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1.0), TOO_LOW);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForMedActiveCoolingHighTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41.0), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesBreachForMedActiveCoolingNormalTemperature) {
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39.0), NORMAL);
}

