#include <gtest/gtest.h>

#include "upstream_c/upstream_c.hpp"

TEST(UpstreamC, LabelsTheWholeChain)
{
  EXPECT_EQ("demo: elements=1", upstream_c::label("demo", "<a/>"));
}

TEST(UpstreamC, LabelsAnInvalidDocument)
{
  EXPECT_EQ("x: invalid", upstream_c::label("x", "<a>"));
}
