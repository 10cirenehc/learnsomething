#include <gtest/gtest.h>
#include <pricingutil.h>

TEST(PricingUtilTest, NormalVals) {
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(10,2.4,0.5), 16.5, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(92.4,1.2,0.8), 155.2320, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(3.2,3.3,0.75), 10.0800, 1e-4);
    EXPECT_NEAR(pricingUtil.getVal(),10.0800, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(92.4,10.0,0.8), 805.728, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(92.4,10.0,0.3), 302.148, 1e-4);
}

TEST(PricingUtilTest, NegativeVals){
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(-10,2.4,0.5), -16.5, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-100,-1.2,0.7), 21.0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-10.2,2.4,-0.1), 3.366, 1e-4);
    EXPECT_NEAR(pricingUtil.getVal(),3.366, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(100,-1.0,-0.7), 7.00, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-100,-1.0,0.7), 7.00, 1e-4);
    EXPECT_NEAR(pricingUtil.getVal(),7.00, 1e-4);
}

TEST(PricingUtilTest, LargeVals) {
    PricingUtil pricingUtil; 
    EXPECT_NEAR(pricingUtil.calcVal(10000000000.0, 10000.0, 100000),1.00009e19, 1e14);
    EXPECT_NEAR(pricingUtil.calcVal(10000000000.0, -10000.0, 100000),-9.9991e18, 1e14);
}

TEST(PricingUtilTest, ZeroVals){
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(0.0,1.1,0.5),0.0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0.0,0.0,0.0),0.0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(10.0,0.0,0.3),2.70, 1e-4);
    EXPECT_NEAR(pricingUtil.getVal(),2.70, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-5,1.2,0.0),0.0,1e-4);
}