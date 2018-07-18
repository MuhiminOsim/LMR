std::string str = ("The the there");
std::regex pattern ("(th|Th)[\\w]*", std::regex_constants::optimize | std::regex_constants::ECMAScript);
std::smatch match;	//std::cmatch for char *

std::regex_match (str, match, pattern);

auto mbegin = std::sregex_iterator (str.begin (), str.end (), pattern);
auto mend = std::sregex_iterator ();
std::cout << "Found " << std::distance (mbegin, mend) << " words:\n";
for (std::sregex_iterator i = mbegin; i != mend; ++i) {
	match = *i;
/*	The word is match[0], backreferences are match[i] up to match.size ().
	match.prefix () and match.suffix () give the prefix and the suffix.
	match.length () gives length and match.position () gives position of the match. */ }
std::regex_replace (str, pattern, "sh$1");
//$n is the backreference, $& is the entire match, $` is the prefix, $' is the suffix, $$ is the $ sign.

