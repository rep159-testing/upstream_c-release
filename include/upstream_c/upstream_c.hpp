#ifndef UPSTREAM_C__UPSTREAM_C_HPP_
#define UPSTREAM_C__UPSTREAM_C_HPP_

#include <string>

namespace upstream_c
{

/// "<name>: " followed by upstream_b's summary of `xml`.
std::string label(const std::string & name, const std::string & xml);

}  // namespace upstream_c

#endif  // UPSTREAM_C__UPSTREAM_C_HPP_
