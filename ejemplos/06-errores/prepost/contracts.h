#ifndef CONTRACTS_H
#define CONTRACTS_H

namespace contracts {
  void contract_log(std::string_view label, std::string_view cond,
      std::string_view function, std::string_view file, std::size_t line) {
    std::cerr << label << ": " << cond <<
        " failed in function " << function << "() ["<< file << ":" << line << "]\n";
  }
}

#define contract_check_imp(label,cond) \
if (cond) [[unlikely]] { \
  contracts::contract_log(label, #cond, __func__, __FILE__, __LINE__); \
  std::terminate(); \
}

#define contract_check(label,cond) contract_check_imp(label,cond)

#ifdef NDEBUG
#define contract_check_audit(label,cond)
#else
#define contract_check_audit(label,cond) contract_check_imp
#endif

#define contract_pre(cond) contract_check("Precondition", cond)
#define contract_pre_audit(cond) contract_check_audit("Precondition", cond)
#define contract_post(cond) contract_check("Postcondition", cond)
#define contract_post_audit(cond) contract_check_audit("Postcondition", cond)
#define contract_assert(cond) contract_check("Assertion", cond)
#define contract_assert_audit(cond) contract_check_audit("Assertion", cond)

#endif //CONTRACTS_H
