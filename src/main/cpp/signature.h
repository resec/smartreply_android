#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#include <string>
#include <vector>

namespace signature {
    /* 
     * Analyzes message for a presence of signature block (by common patterns)
     * and returns message text without signature block
     */
    std::string RemoveSignature(std::string &text, std::string &sender, std::vector<std::string> &recipients);
}

#endif // SIGNATURE_H_
