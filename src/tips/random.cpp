std::mt19937_64 mt (time (0));
std::uniform_int_distribution <int> uid (1, 100);
std::uniform_real_distribution <double> urd (1, 100);
std::cout << uid (mt) << " " << urd (mt) << "\n";

