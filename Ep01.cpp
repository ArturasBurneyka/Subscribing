/*
*	How to build this application:
*	cd d:\Arthur\Subscribing
*	cl.exe /std:c++17 /W4 /EHsc Ep01.cpp /link /out:Subscribing1.exe
*/

#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

auto a() -> void
{
	std::printf("auto a() -> void\n");
}

auto b() -> void
{
	std::cout << "auto b() -> void" << std::endl;
}

auto main(int argc, char *argv[]) -> int
{
	std::vector<auto (*)() -> void> v;
	
	v.push_back(a);
	v.push_back(b);
	
	for (auto it = std::cbegin(v); it != std::cend(v); ++it)
	{
		(*it)();
	}
	
	return 0;
}