#include "upstream_c/upstream_c.hpp"

#include "upstream_b/upstream_b.hpp"

namespace upstream_c
{

std::string label(const std::string & name, const std::string & xml)
{
  return name + ": " + upstream_b::summarize(xml);
}

}  // namespace upstream_c
