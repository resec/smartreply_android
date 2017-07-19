#include <string>
#include <vector>
#include <regex>
#include "signature.h"

//using namespace std::regex_constants;

namespace signature {
    #define __NAME_EMPTY_STRING__   " \t\n\r\f\v"
    #define __GREETING_WORD_LIMIT__ 6
    #define __SIGNATURE_LINE_LENGTH_LIMIT__ 50
    #define __NEWLINE_DELIMITER__   '\n'
    #define __WORD_DELIMITER__   ' '
    #define __TEXTLINE_LIMIT__  50

    /*
     * trim from end of string (right)
     */
    static inline void rtrim(std::string &s) 
    {
        s.erase(s.find_last_not_of(__NAME_EMPTY_STRING__)+1);
    }

    /*
     * trim from beginning of string (left)
     */
    static inline void ltrim(std::string &s)
    {
        s.erase(0, s.find_first_not_of(__NAME_EMPTY_STRING__));
    }

    /*
     * trim the string
     */
    std::string trim(std::string &s)
    {
        ltrim(s);
        rtrim(s);
        return s;
    }

    /*
     * split a string by delimiter
     */
    std::vector<std::string> split(const std::string str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;

        while(std::getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }

    /*
     * merge into a string by delimiter from a string vector
     */
    std::string join(std::vector<std::string> &lines, char delimiter) {
        std::string text = "";
        for (int i=0; i<lines.size(); i++) {
            text = text + lines[i] + delimiter;
        }
        return text;
    }

    /* 
     * Analyzes message for a presence of signature block (by common patterns)
     * and returns message text without signature block
     */
    std::string RemoveSignature(std::string &text, std::string &sender, std::vector<std::string> &recipients) {
        // trim the text
        std::string filtered_text = trim(text);
        
        if (filtered_text.empty()) {
            return filtered_text;
        }

        // Merge multiple newline
        std::regex re_newline ("(\\n[ ]*)+");
        filtered_text = std::regex_replace(filtered_text, re_newline, "\n");

        // split email text into lines
        std::vector<std::string> lines = split(filtered_text, __NEWLINE_DELIMITER__);
        //if (lines.size() >= __TEXTLINE_LIMIT__) {
        //    return "";
        //}

        // remove recipients greeting in first line
        std::string first_line = trim(lines[0]);
        std::vector<std::string> first_line_words = split(first_line, __WORD_DELIMITER__);

        std::regex re_greeting (
               "((?:"
                    "^(hi|hey|dear|hello|good|greeting)[\\w\\s/]*[\\.,!~-]*$"
                ").*)" , std::regex_constants::ECMAScript | std::regex_constants::icase);
        std::smatch greeting_match;

        if (!recipients.empty() && first_line_words.size() <= __GREETING_WORD_LIMIT__) {
            if (std::regex_search(first_line, greeting_match, re_greeting)) {
                // match greeting words in first line, remove it
                lines.erase(lines.begin());
            } else {
                for (int i=0; i<recipients.size(); i++) {
                    std::vector<std::string> recipient_names = split(recipients[i], __WORD_DELIMITER__);
                    for (int j=0; j<recipient_names.size(); j++) {
                        if (first_line.find(recipient_names[j]) != std::string::npos) {
                            // find recipient name in first line, remove it
                            lines.erase(lines.begin());
                            break;
                        }
                    }
                }
            }
        }

        // signatures appended by phone email clients
        std::regex re_phone_signature (
               "((?:"
                       "^sent[ ]{1}from[ ]{1}my[\\s,!\\w]*$"
                       "|"
                       "^sent from Mailbox for iPhone.*$"
                       "|"
                       "^sent[ ]([\\S]*[ ])?from[ ]my[ ]BlackBerry.*$"
                       "|"
                       "^[*]*sent (from|using|on|via) [\\s,!\\w]*$"
                       "|"
                       "^Enviado[ ]desde[ ]mi[ ]([\\S]+[ ]){0,2}BlackBerry.*$"
                   ").*)" , std::regex_constants::ECMAScript | std::regex_constants::icase);

        // strip off phone signature
        std::smatch phone_match;
        for (int i=0; i<lines.size(); i++) {
            if (std::regex_search(trim(lines[i]), phone_match, re_phone_signature)) {
                // match phone signature in line, remove it
                lines.erase(lines.begin()+i, lines.end());
                break;
            }
        }

        // regex to fetch signature based on common signature words
        std::regex re_signature (
               "((?:"
                       "^[\\s]*[-_~\\*][-_~\\*]*[\\s]*[a-z \\.]*$"
                       "|"
                       "^thank[\\s\\w]*[\\s,.!]*$"
                       "|"
                       "^(cheers|sincerely|regards|warmly|kind)[\\s\\w,!]*$"
                       "|"
                       "^best[\\s\\w]*[\\.,!]*$"
                   ").*)" , std::regex_constants::ECMAScript | std::regex_constants::icase);

        std::smatch signature_match;
        // common signature mostly appear at the last part of email 
        // we only check the last 2/3 part of the email
        int line_threshold = int(lines.size()/3);
        for (int i=line_threshold; i<lines.size(); i++) {
            if (std::regex_search(trim(lines[i]), signature_match, re_signature) && \
                (lines[i].length() <= __SIGNATURE_LINE_LENGTH_LIMIT__)) {
                // match common signature in line, remove it
                lines.erase(lines.begin()+i, lines.end());
                break;
            }
        }

        // Only sender name in last few lines
        int signature_threshold = int(lines.size()*2/3);
        std::vector<std::string> sender_names = split(sender, __WORD_DELIMITER__);
        for (int i=signature_threshold; i<lines.size(); i++) {
            std::vector<std::string> line_words = split(lines[i], __WORD_DELIMITER__);
            for (int j=0; j<sender_names.size(); j++) {
                if ((line_words.size() <= __GREETING_WORD_LIMIT__) && \
                    (lines[i].find(sender_names[j]) != std::string::npos)) {
                    // match sender name in line, remove it
                    lines.erase(lines.begin()+i, lines.end());
                    break;
                }
            }
        }

        // merge lines back into text and return
        filtered_text = join(lines, __NEWLINE_DELIMITER__);
        filtered_text = trim(filtered_text);
        return filtered_text;
    }
}
