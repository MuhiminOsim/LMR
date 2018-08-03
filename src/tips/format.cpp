//Faster cin/cout.
std::ios::sync_with_stdio (0);
std::cin.tie (0); std::cout.tie (0);
//getline : gets a line.
std::string str;
std::getline (std::cin, str, '#');
char ch[100];
std::cin.getline (ch, 100, '#');
//fgets : gets a line with '\n' at the end.
fgets (ch, 100, stdin);
//peek : gets the next character.
int c = std::cin.peek ();
//ignore : ignores characters.
std::cin.ignore (100, '#');
std::cin.ignore (100, EOF);
//read : reads all characters.
std::cin.seekg (0, std::cin.end);
int length = std::cin.tellg ();
std::cin.seekg (0, std::cin.beg);
char *buf = new char[length];
std::cin.read (buf, length);
//width : specifies output minimal width.
std::cout.width (10); // std::cout << std::setw (10);
std::cout.fill ('#'); // std::cout << std::setfill ('#');
std::cout << std::left << x << "\n";
std::cout << std::internal << x << "\n";
std::cout << std::right << x << "\n";
//precision : specifies float precision.
std::cout.precision (10); // std::cout << std::setprecision (10);
std::cout << std::fixed; // std::cout << std::scientific;

