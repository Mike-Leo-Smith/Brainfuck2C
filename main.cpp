#include <stdlib.h>
#include <iostream>
#include <fstream>

int main()
{
	int c;
	int intend = 1;
	
	system("echo rm brainfuck.c");
	
	std::ofstream c_file("brainfuck.c");
	
	if (!c_file.is_open()) std::cerr << "error: failed to create file...\n" << std::endl;
	
	c_file << "#include <stdio.h>\n"
	       << "\n"
	       << "char arr[10240];\n"
	       << "\n"
	       << "int main()\n"
	       << "{\n"
	       << "\tchar *ptr = arr;\n"
	       << "\n";
	
	while ((c = std::cin.get()) != EOF && c != '\n')
	{
		switch (c)
		{
		case '>':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "++ptr;\n";
			break;
		case '<':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "--ptr;\n";
			break;
		case '+':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "++*ptr;\n";
			break;
		case '-':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "--*ptr;\n";
			break;
		case '.':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "putchar(*ptr);\n";
			break;
		case ',':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "*ptr = getchar();\n";
			break;
		case '[':
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "while (*ptr)\n";
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "{\n";
			intend++;
			break;
		case ']':
			intend--;
			for (int i = 0; i < intend; i++) c_file << "\t";
			c_file << "}\n";
			break;
		default:
			break;
		}
	}
	
	c_file << "\n"
	       << "\treturn 0;\n"
	       << "}\n";
	c_file.close();
	
	system("gcc -o brainfuck brainfuck.c -O3 && ./brainfuck");
	
	return 0;
}